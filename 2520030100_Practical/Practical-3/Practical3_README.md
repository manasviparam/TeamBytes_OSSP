# OSSP Practical 3

## Objective

Develop a C program using `fork()` that creates a parent and child process. Display the Process ID (PID), Parent Process ID (PPID), and process states at different stages of execution.

Design an experiment to observe process state transitions (Ready, Running, Waiting, Terminated) using Linux monitoring tools such as `ps`, `top`, and `/proc`. Document the observations.

## Work Done

- Created a C program using the `fork()` system call. The `fork()` function creates a new child process from the existing parent process.
- The child process displayed the PID and PPID of both the parent and child processes to identify them separately.
- During the execution of the program, the `ps` command was used to view the processes currently running in the terminal. It displayed the process IDs and the corresponding commands.
- Used the `top` command to continuously monitor the processes while they were executing. It provided a real-time view of the processes and their activity. This helped in observing how the process status changes during execution.
- Used the `/proc` filesystem to inspect the process with PID 666, which was the `a.out` process identified using the `ps` command. The `/proc/666` directory contains different files and directories that provide information about the process, such as its status, memory, scheduling, file descriptors and other process-related details. This helped me observe how Linux maintains information about an active process.
