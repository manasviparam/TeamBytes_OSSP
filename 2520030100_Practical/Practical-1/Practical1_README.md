# OSSP Practical 1

## Objective

Develop a C program that demonstrates how a Linux operating system executes a command entered by a user.

The program should:
1. Accept a Linux command as input.
2. Create a child process using `fork()`.
3. Execute the command in the child process using an appropriate `exec()` system call.
4. Allow the parent process to wait for the child using `wait()`.
5. Display the Process ID (PID) of both parent and child processes.

## Work Done

- Created a file named `prac1.c`.
- Compiled and ran the program where the command `ls` was entered.
- The Child PID has been returned followed by its command execution while the parent process waited till the child process completes.

## Linux Commands

Using Linux terminal commands (`uname`, `lscpu`, `lsblk`, `ps`, `top`), investigated the relationship between hardware resources and operating system services.

### 1. uname

It displays basic information about the Linux operating system and kernel.

### 2. lscpu

It displays CPU information such as the number of CPUs, cores, architecture, and processor details.

### 3. lsblk

It displays the storage devices and partitions available in the system.

### 4. ps

It shows the processes currently running in the system.

### 5. top

It shows running processes along with their CPU and memory usage in real time.

## Hardware and the Operating System

The operating system acts as a link between applications and computer hardware.

- **CPU:** The OS schedules processes and assigns them CPU time.
- **Memory:** The OS allocates RAM to processes and keeps their memory spaces separate.
- **Storage:** The OS manages storage devices and organizes data into files and directories.
- **I/O Devices:** The OS uses device drivers to communicate with devices such as keyboards, displays, and network cards.
