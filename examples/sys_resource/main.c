#include <sys/resource.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>



/*
    sys/resource.h provides a couple of functions:
        getpriority()
        setpriority()
        
        getrlimit()
        setrlimit()

        getrusage()
*/

int main()
{

    pid_t this_process = getpid();
    nice(-2);
    printf("Priority: %d\n", getpriority(PRIO_PROCESS , this_process) );
    
    perror("");




    struct rlimit limit;

    // getrlimit(int, struct r_limit *)
    getrlimit(RLIMIT_CORE, &limit);
    perror("");
    getrlimit(RLIMIT_CPU, &limit);
    perror("");
    getrlimit(RLIMIT_DATA, &limit);
    perror("");
    getrlimit(RLIMIT_FSIZE, &limit);
    perror("");
    getrlimit(RLIMIT_NOFILE, &limit);
    perror("");
    getrlimit(RLIMIT_STACK, &limit);
    perror("");
    getrlimit(RLIMIT_AS, &limit);
    perror("");

    printf("current limit: %ld\n", limit.rlim_cur );
    printf("hard limit: %ld\n", limit.rlim_max );

    /*
        if -1, that means no limit is imposed
    */



    //getrusage(int, struct rusage *)
    struct rusage usage;

    getrusage(RUSAGE_CHILDREN, &usage);
    getrusage(RUSAGE_SELF, &usage);
    printf("signales received: %ld\n", usage.ru_nsignals);
    perror("");



    return 0;
}