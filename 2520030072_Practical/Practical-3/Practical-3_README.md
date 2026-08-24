# Practical 3

## Aim / Objective
To write a C program using fork() that creates a parent and a child process and
displays their Process ID (PID) and Parent Process ID (PPID). Also to observe the
process state transitions (Ready, Running, Waiting, Terminated) using Linux
monitoring tools like ps, top, and /proc.

## Files
- Practical-3.c - source code
- Practical-3_OSSP.pdf - output screenshots

## How to run
gcc Practical-3.c
./a.out

Since the child runs in a loop, it keeps running and can be observed using the
commands below (from another terminal). Note the child PID that is printed, and
kill it when done using `kill <childPID>`.

## What we did
We ran the program which created a child process using fork(), and both processes
printed their PID and PPID. Since the child runs in a loop, it stayed alive so we
could observe it. We used ps and ps u to see the child and its state, top to view
it live, and /proc to read its state directly from the kernel. Finally we used
kill to terminate the process.

## What it does
The program calls fork() to create a child process. The child prints its own PID
and its parent's PID, then enters a loop to keep running. The parent prints its
own PID and its parent's (grandparent) PID. This shows the parent-child
relationship between processes.

## Commands used
- gcc - compiles the program
- ./a.out - runs the program
- ps / ps u - lists processes and shows their state
- top - live view of processes and CPU usage
- ls /proc/<pid> - lists the kernel files about a process
- cat /proc/<pid>/status - reads the process state from the kernel
- kill - terminates the process

## What we learnt
Learned how fork() creates a child process and how PID and PPID identify processes
and their parents. Also learned how to observe process states using ps, top, and
the /proc filesystem, and saw the child in the Running (R) state and confirmed it
was Terminated after using kill.
