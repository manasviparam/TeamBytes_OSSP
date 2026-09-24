# Practical-5

## Aim
To implement a producer-consumer communication system using anonymous pipes, and to develop a program that replicates the shell command `ls -l | grep ".c"` using `fork()`, `pipe()`, `dup2()`, and `exec()` system calls.

## Objectives
1. Implement a producer-consumer communication system using anonymous pipes where the parent process generates data and the child process consumes it. Measure the communication efficiency.
2. Develop a program that executes the equivalent of the shell command `ls -l | grep ".c"` using `fork()`, `pipe()`, `dup2()`, and `exec()` system calls.

## Theory
- An **anonymous pipe** is a unidirectional IPC (Inter-Process Communication) channel used between related processes, such as a parent and child created via `fork()`.
- `pipe()` creates a pair of file descriptors: one end for reading and one for writing.
- In a **producer-consumer** setup, one process (producer) writes data into the pipe while another process (consumer) reads it, ensuring synchronized data transfer without shared memory.
- `dup2()` is used to redirect standard input/output to the pipe's file descriptors (fd 1 for output, fd 0 for input), allowing a process to communicate through the pipe transparently, as if using `stdin`/`stdout`.
- `exec()` replaces the current process image with a new program, which lets the child process run commands like `ls` or `grep` after the pipe has been connected via `dup2()`.
- `clock()` measures CPU time, used here to evaluate the communication efficiency between the producer and consumer.

## What We Did
- For the first part, we created an anonymous pipe and used `fork()` to create a parent and child process. The parent acted as the producer and sent the values 10, 20, 30, 40 and 50 through the pipe. The child acted as the consumer and read the same values.
- We used `clock()` to measure the time taken during the communication, giving an estimate of communication efficiency.
- For the second part, we recreated the behavior of `ls -l | grep ".c"` using system calls instead of the shell. The parent process executed `ls -l` and sent its output into the pipe, while the child process read from the pipe and executed `grep ".c"`.
- `dup2()` was used to connect the pipe to standard output/input: file descriptor 1 (`stdout`) was redirected for the writing process, and file descriptor 0 (`stdin`) was redirected for the reading process.

## Commands Used
- **Producer-consumer:** `gcc Producer.c` → `./a.out`
- **Pipe + exec:** `gcc Practical-5_exec.c` → `./a.out`

## Output
The producer-consumer program successfully produced and consumed all five values, with the time taken for communication displayed in the terminal. The pipe + exec program successfully displayed only the `.c` files from the directory listing, correctly matching the behavior of `ls -l | grep ".c"`.

## Conclusion
We successfully implemented a producer-consumer model using anonymous pipes for IPC between a parent and child process, and measured the communication efficiency using `clock()`. We also implemented a program using `fork()`, `pipe()`, `dup2()`, and `exec()` to replicate the shell pipeline `ls -l | grep ".c"`, demonstrating how pipes and file descriptor redirection can be used to chain process input/output at the system call level.
