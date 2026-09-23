# OSSP Practical 5

## Objective

Implement producer-consumer communication using an anonymous pipe and measure the communication time.

## Work Done

Created a C program named `Practical-5.c`.

The parent process acts as the producer and sends 5 integer values through an anonymous pipe. The child process acts as the consumer and reads the values from the pipe.

The program uses `fork()` to create the child process, `pipe()` for communication, and `close()` to close the unused pipe ends. The communication time is measured using `clock()`.

## Compile and Run

```bash
gcc Practical-5.c -o practical5
./practical5
```
