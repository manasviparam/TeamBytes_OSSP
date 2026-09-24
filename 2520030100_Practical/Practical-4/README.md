# OSSP Practical 4

## Objective

Develop C programs to demonstrate process synchronization using `wait()`, `waitpid()`, and zombie process handling.

## Work Done

### 1. Wait and Waitpid

Created 3 child processes using `fork()`. The parent uses `wait()` to wait for any completed child and `waitpid()` to wait specifically for the third child. Finally, `wait()` is used for the remaining child processes.

### 2. Zombie Process

Created a child process that terminates while the parent sleeps for 30 seconds. During this time, the child can be observed as a zombie in the process table. The parent then uses `wait()` to collect the child's exit status and remove the zombie process.

`wait()` waits for any completed child, whereas `waitpid()` waits for a specific child process.

## Compile and Run

### Wait and Waitpid

```bash
gcc Practical-4_Waitpid.c -o waitpid
./waitpid
```

### Zombie Process

```bash
gcc Practical-4_Zombie.c -o zombie
./zombie
```

During the 30-second delay, the zombie process can be checked using:

```bash
ps
```
