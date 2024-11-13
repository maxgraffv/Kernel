#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>
#include <sys/mman.h>





int main(int argc, char** argv)
{

    //OPENING CAMERA
    int camf = open("/dev/video0", O_RDWR);
    if(camf == -1)
    {
        perror("Opening cam failed");
        return EXIT_FAILURE;
    }


    struct v4l2_capability cap;
    if( ioctl(camf, VIDIOC_QUERYCAP, &cap) == -1)
    {
        perror("Querrying capabilities");

        return EXIT_FAILURE;
    }

    printf("Driver: %s\n", cap.driver);
    printf("Card: %s\n", cap.card);
    printf("Bus Info: %s\n", cap.bus_info);
    printf("Capabilities: %d\n", cap.capabilities);
    printf("Version: %d\n", cap.version);

    struct v4l2_format fmt;
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width = 640;
    fmt.fmt.pix.height = 480;
    fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
    fmt.fmt.pix.field = V4L2_FIELD_INTERLACED;

    if( ioctl(camf, VIDIOC_S_FMT, &fmt) == -1 )
    {
        perror("Setting Pixel Format");

        return EXIT_FAILURE;
    }

    struct v4l2_requestbuffers req;
    req.count = 1;
    req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    req.memory = V4L2_MEMORY_MMAP;

    if( ioctl( camf, VIDIOC_REQBUFS, &req) == -1)
    {
        perror("Requesting buffer");
        return EXIT_FAILURE;
    }





    struct v4l2_buffer buf;
    buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.memory = V4L2_MEMORY_MMAP;
    buf.index = 0;


    if( ioctl( camf, VIDIOC_QUERYBUF, &buf) == -1)
    {
        perror("Querying buffer");
        return EXIT_FAILURE;
    }

    void* buffer = mmap(NULL, buf.length, PROT_READ | PROT_WRITE, MAP_SHARED, camf, buf.m.offset);
    if(buffer == MAP_FAILED)
    {
        perror("Mapping buffer");
        return EXIT_FAILURE;
    }

    printf("CHECK\n");

    int type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if( ioctl( camf, VIDIOC_STREAMON, &type) == -1)
    {
        perror("Starting Capture");
        return EXIT_FAILURE;
    }
    printf("CHECK\n");

    if( ioctl( camf, VIDIOC_QBUF, &buf) == -1)
    {
        perror("Queue buffer");
        return EXIT_FAILURE;
    }

    if( ioctl( camf, VIDIOC_DQBUF, &buf) == -1)
    {
        perror("Dequeue buffer");
        return EXIT_FAILURE;
    }

    printf("CHECK\n");
    printf("Captured %d bytes of data", buf.bytesused);

    FILE *file = fopen("img.raw", "wb");
    if(file == NULL)
    {
        perror("Opening file to save image");
        munmap(buffer, buf.length);
        close(camf);
        return EXIT_FAILURE;
    }

    fwrite(buffer, buf.bytesused, 1, file);
    fclose(file);
    printf("Image saved");


    if( ioctl( camf, VIDIOC_STREAMOFF, &type) == -1)
    {
        perror("Stopping Capture");
        return EXIT_FAILURE;
    }

    munmap(buffer, buf.length);
    close(camf);

}