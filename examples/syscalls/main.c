#define _GNU_SOURCE //clone()
#include <sched.h> //clone() and sched_param struct

#include <stdio.h>
#include <stdlib.h>

#include <sys/wait.h>
#include <sys/resource.h> // PRIO_PROCESS and RLIMIT
#include <sys/prctl.h> // prctl()

#include <unistd.h> // fork()
#include <fcntl.h> // defined pid_t (only vscode fix, not needed for compilation)
#include <pwd.h> // get user info by UID
#include <signal.h> //SIGCHLD
#include <linux/sched.h> //CLONE_VM and other flags

void processMgmt();

int main(int argc, char** argv)
{
	/*
		PROCESS MANAGEMENT
	*/






	processMgmt();



	/*
		FILE OPERATIONS
	*/

	// open();
	// close()
	// read()
	// write()

	// lseek()

	// stat()
	// fstat()
	// lstat(

	// rename()
	// mkdir()
	// rmdir()

	// unlink()

	// chmod()
	// fchmod()

	// fsync()
	// fdatasync()

	// access()

	// flock()

	// readlink()
	// symlink()
	// link()
	// umask()
	// getcwd()
	// chdir()
	//fchdir()
	//mknod()




	/*
		MEMORY MANAGEMENT
	*/


	// brk()
	// mmap()
	// munmap()
	//mprotect()
	//mlock()
	//munlock()
	//shmget()
	//shmat()
	//shmdt()
	//shmctl()


 


	/*
	SIGNALS
	*/

	// kill();

	return 0;
}

int void_fun(void* arg)
{
	printf("void function executing...\n");
	return 0;
}

void processMgmt()
{
	printf("before\n");
	//getuid()
	pid_t uid = getuid();
	// if uid == 0; User is ROOT
	printf("UID %d\n", uid);
	struct passwd *pw = getpwuid(uid);


	if(pw)
	{
		printf("Username: %s\n", pw->pw_name);
		printf("Home Dir: %s\n", pw->pw_dir);
		printf("Shell: %s\n", pw->pw_shell);
	}
	


	//getpid()
	pid_t program_pid = getpid();

	//getppid()
	pid_t parent_pid = getppid();

	// fork();
	pid_t child_pid = fork();
	printf("after\n");


	printf("parent: %d\t", parent_pid);
	printf("program: %d\t", program_pid);
	printf("child: %d\t", child_pid);
	



	// execve()
	extern char **environ;


	if(child_pid == 0)
	{
		// Child process
		char *custom_env[] = {"MY_VAR=Hello", "PATH=/usr/bin", NULL};
		char* execv[] = {"ls", "-la", NULL};

		// getpriority()
		int who = 0;
		printf("Child Process Priority: %d\n", getpriority(PRIO_PROCESS, who));
		/*
		 	PRIO_PROCESS - process priority, who is process id
			PRIO_PGRP - process group priority, who is process group id
			PRIO_USER - user priority, who is user id
			if who 0, refers to the calling process, group or user
		
		*/

  		// setpriority()
		setpriority(PRIO_PROCESS, 0, 10);
		/*
			priority ranges from -20 (highest priority) to 19(lowest priority)
			default priority is 0
		*/

		// nice();
		nice(5);
		/*
			Niceness decreases priority, nice(3) reducts priosity by 3
		*/
		printf("Child Process Priority: %d\n", getpriority(PRIO_PROCESS, who));

		// execve( "/bin/ls", execv, NULL);
		printf("No execution\n");
	}
	else if (child_pid > 0)
	{
		// Parent process
		char* execv[] = {"cat", "main.c", NULL};
		// execve( "/bin/cat", execv , NULL);
		printf("No execution\n"); // if execve executes, anything after will not
		
		//wait()
		int status = 0;
		pid_t wait_pid = wait(&status);
		if(wait_pid == -1)
		{
			perror("wait failed");
			exit(1);
		}

		if( WIFEXITED(status) )
			printf("Child exited with: %d\n", WEXITSTATUS(status));
		if( WIFSIGNALED(status))
			printf("Child terminated by signal: %d", WTERMSIG(status));



	}
	else
	{
		// fork failed
		perror("Fork Failed\n");
	}
	


	// clone();
	char* stack = (char*)malloc(1024*1024*sizeof(char));
	if(!stack)
	{
		perror("Malloc fail\n");
		//exit()
		exit(1);
		/*
			EXIT_SUCCESS 0
			EXIT_FAILURE 1
			EXIT_CUSTOM 2...etc
			read with echo $?
		*/
	}
	char* stack_top = stack + 1024;
	clone( void_fun, stack_top, CLONE_VM | CLONE_FILES | SIGCHLD, NULL );
	sleep(1);
	free(stack);


	//sched_yield()
	sched_yield();
	

	struct sched_param param;
	param.sched_priority = 0;
	sched_setparam(0, &param); // 0 is current pid
	// sched_get param, takes (pid_t, &param) and sets param as current priority

	//sched_setscheduler()
	sched_setscheduler(0, SCHED_RR, &param);
	/*
		0 is current pid

		SCHED_RR - Round-robin realtime scheduling
		SCHED_FIFO - FIFO realtime scheduling
		SCHED_OTHER - default, non-real-time scheduling

		&param - pointer to sched_param
	*/

 	//sched_getscheduler()
	sched_getscheduler(0);
	/*
		returns SCHED_RR/FIFO/OTHER
	*/

	sched_get_priority_max(SCHED_RR); // gets maximum priority value for a given scheduling policy
	sched_get_priority_min(SCHED_RR); // gets minimum priority value for a given scheduling policy

	//resource limit
	struct rlimit rlim;
	/*
		rlimit struct:
			rlim_t rlim_cur; - soft limit
			rlim_t rlim_max; - hard limit
	*/
	// getrlimit();
	getrlimit(RLIMIT_NOFILE, &rlim); // retrieved the current resource limit for the calling process
	/*
		resource:
			RLIMIT_CPU - cpu time in seconds
			RLIMIT_FSIZE - max file size that can be created
			RLIMIT_DATA - max size data segment
			RLIMIT_STACK - max stack size
			RLIMIT_CORE - max size of core file that the process may dump
			RLIMIT_NOFILE - max num of open file descriptors
			RLIMIT_AS - max address space that may be used by the process (virtual memory)
	*/

	// setrlimit();
	rlim.rlim_cur = 1024;
	setrlimit(RLIMIT_NOFILE, &rlim);


	// prctl();
	prctl(PR_SET_NAME, (unsigned long)("CustomName"));
	prctl(PR_SET_DUMPABLE, 1);
	/*
		PR_SET_NAME - set name of calling process
		PR_GET_NAME - get name of calling process
		PR_SET_DUMPABLE - sets whether the process is allowed core dumps
		PR_GET_DUMPABLE - gets whether the process is allowed core dumps
		PR_SET_PDEATHS - sets signal to be sent to process when parent dies
		PR_GET_PDEATHS - gets signal to be sent to process when parent dies
		PR_SET_NO_NEW_PRIVS - prevents the process from gaining new privilages
		PR_GET_NO_NEW_PRIVS - gets state of the "no new privilages" flag
		PR_SET_SECCOMP - enables seccomp mode, used for sandboxing
		PR_GET_SECCOMP - gets current seccomp mode
	
		1 - enables
		prctl takes 4 arguments, depends on first selected
	
	*/
};
