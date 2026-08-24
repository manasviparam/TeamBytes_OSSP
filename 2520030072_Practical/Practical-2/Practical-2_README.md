# Practical 2

## Aim / Objective
To write a C program using the system calls open(), read(), write(), and close()
to copy the contents of one file into another. Also to use the strace utility to
trace the system calls made by the command cat and understand the kernel services
involved.

## Files
- Practical-2.c - source code
- input.txt - input file (contents to copy from)
- output.txt - output file (created by the program)
- Practical-2_OSSP.pdf - output screenshots

## How to run
gcc Practical-2.c
./a.out

Make sure input.txt exists before running. 
Then check the copy with:  cat output.txt


## What we did
First we created an input file input.txt and wrote some text in it. Then we ran
the program which opened input.txt, read its contents, and wrote them into a new
file output.txt. We checked output.txt using cat to confirm the copy worked.
After that we used the strace command on cat to see all the system calls the
command makes while running.

## What it does
The program opens the source file with open() in read mode and creates the
destination file with open() in write mode. It reads the data from the source
file using read() and writes it into the destination file using write(). Finally
both files are closed using close() and a success message is printed.

## Commands used
- gcc - compiles the C program
- ./a.out - runs the program
- cat - displays file contents
- strace - traces the system calls made by a command

## What we learnt
Learned how to use low-level file system calls open(), read(), write() and close()
to copy a file. Also understood how control moves between user space and kernel
space, since each system call switches into the kernel to do the actual work. Using
strace showed the sequence of system calls a command makes and the kernel services
behind them.

