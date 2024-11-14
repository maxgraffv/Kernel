gcc main.c -o main

./main

ffmpeg -f rawvideo -pix_fmt yuyv422 -s 640x480 -i img.raw -f image2 -vcodec png ./png_img.png

open ./png_img.png

rm ./main
rm ./img.raw
