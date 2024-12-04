#include <fcntl.h>




int main()
{
	/*
	fcntl(int fd, int cmd, ...)
	 
	common Commands:
		F_DUPED - duplicates file descriptor
		F_GETFD - gets file descriptor flags
		F_SETFD - sets file descriptor flags
		F_GETFL - gets file status flags
		F_SETFL - sets file status flags
		F_SETLK, F_SETLW, F_GETLK - file locking

		File Locking:
			F_RDLCK - read lock
			F_WRLCK - write lock
			F_UNLCK - unlock
	*/

	/*
	 open(char* pathname, int flags)
	 	flags: O_RDONLY, O_WRONLY, O_RDWR

	openat(int dirfd, char* pathname, int flags) - open() but relative to directory file descriptor
	AT_FDCWD - current working directory
	 */


	/*
	 creat(char* pathname, mode_t mode)

		O_CREAT - create file if doesnt exist
		O_EXCL - ensure file is created; fail if already existscreate file if doesnt exist
		O_TRUNC - truncate the file to zero length
		O_APPEND - write data to the end of the file
		O_NONBLOCK - nonblocking mode
		O_DSYNC, O_SYNC - write operations wait for data integrity completion
		O_NOFOLLOW - do not follow symbolic links
		O_DIRECOTRY - fail if the file is not a directory
	 */






}
