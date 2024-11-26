#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
	/*
		C Std Lib defines an integer variable - errno
			errno is set by syscalls and some library functions when an error occurs

		Errno.h defines Macros - constants suitable for error types ONLY !!!

		To perform any function, when it comes to error handling, other libraries come to the scene

		stdio.h
			perror("");

		string.h
			strerror(errno);
	*/
	printf("Error before: %d\n", errno);

	FILE* f = fopen("file.txt", "r");

	printf("Error after: %d\n", errno);

	if(f == NULL)
	{
		perror("");
		printf("Problem description: %s\n", strerror(errno));
	}





	return 0;
}
