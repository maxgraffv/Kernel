# Kernel
Linux Kernel cheatsheet

# Linux System Calls Grouped by Category

## 1. Process Management
- **`fork()`**: Creates a new process, duplicating the calling process.
- **`execve()`**: Replaces the current process image with a new one.
- **`exit()`**: Terminates the calling process and returns a status to the parent.
- **`wait()` / `waitpid()`**: Waits for a child process to change state (e.g., terminate).
- **`getpid()`**: Returns the process ID of the calling process.
- **`getppid()`**: Returns the parent process ID.
- **`getuid()`**: Returns the real user ID of the calling process.
- **`geteuid()`**: Returns the effective user ID of the calling process.
- **`getgid()`**: Returns the real group ID of the calling process.
- **`getegid()`**: Returns the effective group ID of the calling process.
- **`setuid()`**: Sets the user ID of the calling process.
- **`setgid()`**: Sets the group ID of the calling process.
- **`getpriority()`**: Gets the priority of a process.
- **`setpriority()`**: Sets the priority of a process.
- **`nice()`**: Changes the priority of a process.
- **`sched_yield()`**: Yields the processor to allow other processes to run.
- **`sched_setparam()`**: Sets the scheduling parameters of a process.
- **`sched_getparam()`**: Gets the scheduling parameters of a process.
- **`sched_setscheduler()`**: Sets the scheduling policy and parameters.
- **`sched_getscheduler()`**: Gets the scheduling policy.
- **`sched_get_priority_max()`**: Gets the maximum priority value for a scheduling policy.
- **`sched_get_priority_min()`**: Gets the minimum priority value for a scheduling policy.
- **`setrlimit()`**: Sets resource limits for a process.
- **`getrlimit()`**: Gets resource limits for a process.
- **`prctl()`**: Operations on a process, like setting the name of a process.
- **`clone()`**: Creates a new process, similar to `fork()`, with more control over what is shared.
- **`reboot()`**: Reboots or shuts down the system.

## 2. File Operations
- **`open()`**: Opens a file and returns a file descriptor.
- **`close()`**: Closes a file descriptor.
- **`read()`**: Reads data from a file descriptor.
- **`write()`**: Writes data to a file descriptor.
- **`lseek()`**: Repositions the file offset of an open file.
- **`stat()`** / **`fstat()`** / **`lstat()`**: Gets file status information.
- **`rename()`**: Renames a file or directory.
- **`unlink()`**: Deletes a name from the file system (deletes a file).
- **`rmdir()`**: Removes a directory.
- **`mkdir()`**: Creates a new directory.
- **`chmod()`**: Changes the permissions of a file.
- **`fchmod()`**: Changes the permissions of a file using a file descriptor.
- **`chown()`**: Changes the owner and group of a file.
- **`fchown()`**: Changes the owner and group of a file using a file descriptor.
- **`truncate()`**: Truncates a file to a specified length.
- **`ftruncate()`**: Truncates a file using a file descriptor.
- **`mmap()`**: Maps a file or device into memory.
- **`munmap()`**: Unmaps a memory region that was previously mapped.
- **`fsync()`**: Flushes changes to a file to disk.
- **`fdatasync()`**: Similar to `fsync()`, but only flushes essential data.
- **`access()`**: Checks the permissions of a file.
- **`fstatfs()`**: Gets file system statistics.
- **`flock()`**: Applies or removes an advisory lock on an open file.
- **`readlink()`**: Reads the value of a symbolic link.
- **`symlink()`**: Creates a symbolic link.
- **`link()`**: Creates a hard link.
- **`umask()`**: Sets the file mode creation mask.
- **`getcwd()`**: Gets the current working directory.
- **`chdir()`**: Changes the current working directory.
- **`fchdir()`**: Changes the current working directory using a file descriptor.
- **`mknod()`**: Creates a filesystem node (e.g., a file, device, or pipe).

## 3. Memory Management
- **`brk()`**: Changes the end of the data segment, used for memory allocation.
- **`mmap()`**: Maps a file or device into memory.
- **`munmap()`**: Unmaps memory previously mapped with `mmap()`.
- **`mprotect()`**: Changes the protection of a memory region.
- **`mlock()`**: Locks a memory region, preventing it from being swapped.
- **`munlock()`**: Unlocks a memory region.
- **`shmget()`**: Allocates a shared memory segment.
- **`shmat()`**: Attaches a shared memory segment to the address space.
- **`shmdt()`**: Detaches a shared memory segment.
- **`shmctl()`**: Controls shared memory operations.

## 4. Networking
- **`socket()`**: Creates a socket.
- **`bind()`**: Binds a socket to an address.
- **`listen()`**: Listens for incoming connections.
- **`accept()`**: Accepts an incoming connection.
- **`connect()`**: Connects a socket to a remote address.
- **`send()`**: Sends data on a connected socket.
- **`recv()`**: Receives data on a connected socket.
- **`sendto()`**: Sends data to a specific address.
- **`recvfrom()`**: Receives data from a specific address.
- **`shutdown()`**: Shuts down part of a full-duplex connection.
- **`setsockopt()`**: Sets options on a socket.
- **`getsockopt()`**: Gets options on a socket.
- **`getsockname()`**: Gets the address of the local socket.
- **`getpeername()`**: Gets the address of the remote socket.
- **`select()`**: Monitors multiple file descriptors for I/O readiness.
- **`poll()`**: Similar to `select()`, monitors file descriptors for I/O readiness.
- **`epoll_create()`**: Creates an epoll instance.
- **`epoll_ctl()`**: Controls an epoll instance.
- **`epoll_wait()`**: Waits for events on an epoll instance.

## 5. Inter-Process Communication (IPC)
- **`pipe()`**: Creates a unidirectional pipe for communication between processes.
- **`msgget()`**: Creates or gets a message queue.
- **`msgsnd()`**: Sends a message to a message queue.
- **`msgrcv()`**: Receives a message from a message queue.
- **`semget()`**: Creates or gets a semaphore set.
- **`semop()`**: Performs operations on semaphores.
- **`semctl()`**: Controls semaphore operations.
- **`shmget()`**: Allocates a shared memory segment.
- **`shmat()`**: Attaches a shared memory segment.
- **`shmdt()`**: Detaches a shared memory segment.
- **`shmctl()`**: Controls shared memory operations.
- **`socketpair()`**: Creates a pair of connected sockets for IPC.

## 6. Signals
- **`signal()`**: Sets a signal handler for a specific signal.
- **`kill()`**: Sends a signal to a process or a group of processes.
- **`raise()`**: Sends a signal to the calling process.
- **`sigaction()`**: Examines or changes the action for a specific signal.
- **`sigprocmask()`**: Examines or changes the set of blocked signals.
- **`sigpending()`**: Checks for pending signals.
- **`sigsuspend()`**: Temporarily replaces the signal mask and waits for a signal.
- **`pause()`**: Waits for a signal to arrive.

## 7. System Information and Management
- **`uname()`**: Gets information about the system (e.g., kernel name and version).
- **`sysinfo()`**: Provides information about system memory, load, and uptime.
- **`gethostname()`**: Gets the hostname of the system.
- **`sethostname()`**: Sets the hostname of the system.
- **`gettimeofday()`**: Gets the current time of day.
- **`settimeofday()`**: Sets the current time of day.
- **`times()`**: Returns process and child process times.
- **`syslog()`**: Sends a message to the system logger.
- **`reboot()`**: Reboots the system.

## 8. Device Management
- **`ioctl()`**: Performs device-specific input/output operations.
- **`ioperm()`**: Sets


<br><br>

# To Be Done
- [ ] File Operations
  - [ ] unistd.h
  - [ ] sys/file.h
  - [ ] sys/epoll.h
- [ ] Process Control
  - [ ] sys/wait.h
  - [ ] signal.h
- [ ] IPC
  - [ ] sys/ipc.h
  - [ ] sys/shm.h
  - [ ] sys/sem.h
  - [ ] sys/msg.h
- [ ] Memory
  - [ ] stdlib.h
  - [ ] string.h
- [ ] Sys
  - [ ] mman.h
  - [ ] eventfd.h
- [ ] Dynamic Library
  - [ ] dlfcn.h
