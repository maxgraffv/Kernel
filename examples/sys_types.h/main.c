#include <sys/types.h>

int main()
{
    /*
        sys/types.h provides many structures used in system programming.
        Often used for representing sizes, process ID, user ID and other specific functons.
        Many of them are basic data types like integer or long, signed or unsigned.

        like pid_t - which is defined as
            typedef int pid_t
    */

    dev_t device_id;
    gid_t group_id;
    pid_t process_id;
    uid_t user_id;

    size_t size_of_object_in_bytes;
    ssize_t signed_size_of_object_in_bytes;

    time_t time_since_unix_epoch_in_sec;

    /*
        pthread_t included in pthread.h
    */



    return 0;
}