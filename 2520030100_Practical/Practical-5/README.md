# OSSP Practical 5

## Objectives

1. Implement producer-consumer communication using an anonymous pipe and measure the communication time.

2. Develop a program that executes the equivalent of the shell command:
   `ls -l | grep ".c"`

   using `fork()`, `pipe()`, `dup2()`, and `exec()` system calls.

## Work Done

### 1. Producer-Consumer Communication

Created a C program for producer-consumer communication using an anonymous pipe.

- The parent process acts as the producer and sends 5 integer values: 10, 20, 30, 40, and 50.
- The child process acts as the consumer and reads the values from the pipe.
- `pipe()` is used for communication and `fork()` creates the child process.
- Unused pipe ends are closed using `close()`.
- Communication time is measured using `clock()`.
- The executed output successfully shows the values produced by the parent and consumed by the child.

### 2. `ls -l | grep ".c"` Using System Calls

Created a C program that reproduces the behavior of the shell pipeline `ls -l | grep ".c"`.

- `pipe()` creates the communication channel between the two processes.
- `fork()` creates the child process.
- `dup2()` redirects the standard output/input so the output of `ls -l` becomes the input to `grep`.
- `exec()` is used to execute the required commands.
- The final output displays the `.c` source files in the working directory.

## Compile and Run

```bash
gcc Practical-5.c -o practical5
./practical5
```

For the second program, compile the corresponding C source file and run the generated executable to observe the `ls -l | grep ".c"` output.
