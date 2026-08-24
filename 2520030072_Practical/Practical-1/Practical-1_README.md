# Practical 1

## Aim / Objective
To write a C program that takes a Linux command from the user and runs it in a
child process using fork() and exec(), while the parent waits for the child to
finish using wait(). Also to explore basic Linux system commands (uname, lscpu,
lsblk, ps, top) and understand how the OS manages hardware resources.

## Files
- Practical_1.c - source code
- OSSP_Practical_1.pdf - output screenshots

## How to run
gcc Practical_1.c
./a.out

Then type a command like `ls` or `pwd` when it asks.

## What it does
The program creates a child process with fork(). The child prints its PID and
runs the command using execlp(). The parent waits for the child to finish using
wait(), then prints its own PID.

## Commands used
- uname - shows the OS
- lscpu - CPU info
- lsblk - storage devices
- ps - running processes
- top - live system usage

## What we learnt
Learned how process creation works in Linux using fork(), how a command runs
in a child process using exec(), and how the parent waits for the child using
wait(). Also understood how basic Linux commands show the way the OS manages
CPU, memory, and storage.
