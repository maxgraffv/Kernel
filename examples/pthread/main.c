#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>



void* thread_func()
{
    printf("Hejka\n");
    pthread_exit(0);
}

void exit_func(void*)
{
    printf("exiting\n");
}

void* detached_func()
{

    for(int i = 0; i < 7; i++)
        printf("Detached from reality\n");

    if(atexit(exit_func))
    {

    }
}

pthread_mutex_t mutex;

void* data_grab(int* dp)
{
    for(int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&mutex);
        dp -= 1;
        pthread_mutex_unlock(&mutex);
    }
}


int main()
{
    // declare threads
    pthread_t t1, t2;


    // Create Threads
    // pthread_create(&thread, &attr ,&func, &args_to_func)
    pthread_create(&t1, NULL, &thread_func, NULL );
    pthread_create(&t2, NULL, &thread_func, NULL );


    // Wait for t1 to finish/terminate; Then wait for t2 to finish/terminate as well
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);


    /*
        You can make sure that a thread runs only once using pthred_once() - but it sucks so no example here;
    */


   /*
        Detach Thread; 
        Used when thread performs self-contained tasks. And has no need for its status and results.
        Autamatically releases resources back, when terminated.
   */
   pthread_t thr_detached;
   pthread_create(&thr_detached, NULL, &detached_func, NULL);
   pthread_detach(thr_detached);

    pthread_join(thr_detached, NULL);
    // printf("Equal: %d\n", pthread_equal(thr_detached, t1));
    perror("");





    pthread_create(&t1, NULL, &thread_func, NULL );
    pthread_cancel(t1);



    /*
        MUTEX - Mutual Exclusion
        Locks data shared between threads when accessed by one;
    */


    int data = 2000000;
    int* data_ptr = &data;


   pthread_mutex_init(&mutex, NULL);

   pthread_create(&t1, NULL, &data_grab, data_ptr);
   pthread_create(&t2, NULL, &data_grab, data_ptr);



   sleep(15);

   printf("DATA: %d\n", data);




    pthread_mutex_destroy(&mutex);


    int old;
    // Prioceiling get/set - thread with a higher priority can proceed without being blocked
    pthread_mutex_setprioceiling(&mutex, 18, &old);








    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_attr_setstacksize(&attr, 1024*1024);

    pthread_create(&t1, &attr, &thread_func, NULL);

    // after being passed to a thread, it is no longer needed
    pthread_attr_destroy(&attr);



    /*
        pthread condition variable - synchronization mechanism 
            that allows threads to communicate by signaling when some conditions have been met.
            Works in conjunction with mutex
            Enables a thread to block until condition is met
            Unblocked when another thread signals a condition has been met.
    
    */

    // pthread_cond_wait();
    // pthread_cond_signal();
    // pthread_cond_broadcast();









    /* 
        Pthread_key - allows each thread to have its own private copy of a variable, even if variable is global or shared
    */

   pthread_key_t key;

   

   pthread_key_create(key, &data);
   pthread_setspecific(key, &data);
   pthread_getspecific(key);
   pthread_key_delete(key);



    return 0;
}