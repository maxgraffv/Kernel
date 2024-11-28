#include <time.h>
#include <sys/time.h>

#include <stdio.h>

struct mystruct
{
    int a;
};

int main()
{

    /*
        TIME_H


    */

   time_t time_type = time(NULL);
   struct tm* tm_struct = localtime(&time_type);

   printf("time_type %ld\n", time_type);
   printf("time_type %d:%d %d-%d-%d [%d]\n", tm_struct->tm_hour, tm_struct->tm_min, tm_struct->tm_year+1900, tm_struct->tm_mon+1 ,tm_struct->tm_mday, tm_struct->tm_wday);


    /*
        SYS/TIME_H


    */
    struct timeval tv;
    gettimeofday(&tv, NULL);

    printf("timeval: %ld\n", tv.tv_sec);


    struct mystruct ms;
    ms.a = 5;

    struct mystruct* msptr;
    msptr->a;


    return 0;
}