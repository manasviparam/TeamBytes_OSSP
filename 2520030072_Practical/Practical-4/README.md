# OSSP – Practical 4

## Title
Process Synchronization using `wait()` and `waitpid()` and Zombie Process Handling

## Aim
To create multiple child processes and synchronize their completion using `wait()` and `waitpid()`, compare their behavior, and understand zombie process handling using proper synchronization.

## Problem Statement
Write a C program where a parent process creates multiple child processes and synchronizes their completion using `wait()` and `waitpid()`. Compare the behavior of both functions.

Create a scenario where a child process becomes a zombie process. Investigate the process table and then modify the program to eliminate zombie processes using proper synchronization techniques.

## Concepts Used
- `fork()`
- `wait()`
- `waitpid()`
- Parent and Child Processes
- Process Synchronization
- Process ID (PID)
- Zombie Process

## Procedure

### 1. Multiple Child Processes
- Created three child processes using `fork()`.
- Each child displays its Process ID.
- The parent uses `wait()` to wait for any child process.
- The parent uses `waitpid()` to specifically wait for the third child.
- The remaining child is synchronized using `wait()`.

### 2. Zombie Process
- Created a parent and child process.
- The child terminates after completing its execution.
- The process behavior is investigated using Linux process-management commands.
- Proper use of `wait()` ensures that the parent collects the child's exit status.
- This prevents the terminated child from remaining as a zombie process.
-OUTPUT
- parent process 7000
child process 7001
Parent process completed

## Compilation and Execution
Observations
Multiple child processes were successfully created.
The order in which child processes print their PIDs may vary because process scheduling is handled by the OS.
wait() was used to synchronize with any child.
waitpid() was used to specifically synchronize with child 3.
Proper synchronization allows the parent to collect the child's termination status.
Result

Multiple child processes were successfully created and synchronized using wait() and waitpid(). The difference between both functions was observed, and proper synchronization for zombie-process handling was demonstrated.


**GitHub folder:**

```text
Practical-4/
├── waitex.c
├── Zombie.c
└── README.md
output include

Yep — include the actual outputs in the README too. Use this:

# OSSP – Practical 4

## Title
Process Synchronization using `wait()` and `waitpid()` and Zombie Process Handling

## Aim
To create multiple child processes and synchronize their completion using `wait()` and `waitpid()`, compare their behavior, and understand zombie process handling using proper synchronization.

## Problem Statement
Write a C program where a parent process creates multiple child processes and synchronizes their completion using `wait()` and `waitpid()`. Compare the behavior of both functions.

Create a scenario where a child process becomes a zombie process. Investigate the process table and then modify the program to eliminate zombie processes using proper synchronization techniques.

## Concepts Used
- `fork()`
- `wait()`
- `waitpid()`
- Parent and Child Processes
- Process Synchronization
- Process ID (PID)
- Zombie Process

## Procedure

### 1. Multiple Child Processes
- Created three child processes using `fork()`.
- Each child displays its Process ID.
- The parent uses `wait()` to wait for any child process.
- The parent uses `waitpid()` to specifically wait for the third child.
- The remaining child is synchronized using `wait()`.

### 2. Zombie Process
- Created a parent and child process.
- The child terminates after completing its execution.
- The parent uses `wait()` to collect the child's exit status.
- This demonstrates proper synchronization and prevents the terminated child from remaining as a zombie process.

## Compilation and Execution

```bash
gcc waitex.c
./a.out

gcc Zombie.c
./a.out
Output
Output 1 – wait() and waitpid()
manu@Manasvi:~$ gcc waitex.c
manu@Manasvi:~$ ./a.out
child 2 pid = 3152
child 1 pid = 3151
child 3 pid = 3153
parent: Any one child complete with wait()
parent: child 3 completes with waitpid()
all the childs completed
manu@Manasvi:~$
Output 2 – Zombie Process Handling
manu@Manasvi:~$ gcc Zombie.c
manu@Manasvi:~$ ./a.out
parent process 7000
child process 7001
Parent process completed
manu@Manasvi:~$
wait() vs waitpid()
Function	Behavior
wait()	Waits for any one child process to terminate.
waitpid()	Waits for a specific child process using its PID.
Observations
Three child processes were successfully created.
The child PIDs were 3152, 3151, and 3153.
wait() synchronized the parent with any child process.
waitpid() specifically synchronized the parent with child 3.
The parent and child processes in the zombie demonstration were successfully executed.
Proper use of wait() allows the parent to collect the child's termination status.
Result

Multiple child processes were successfully created and synchronized using wait() and waitpid(). The difference between both functions was observed, and proper synchronization for zombie-process handling was demonstrated.


**Folder:**
```text
Practical-4/
├── waitex.c
├── Zombie.c
└── README.md

Yep — you want the README to document what we actually did + process concepts + commands + actual outputs + observations + result, not just the question.

Use this as the final README.md:

# OSSP – Practical 4

## Process Synchronization using wait() and waitpid() and Zombie Process Handling

## Aim

To create multiple child processes and synchronize their completion using `wait()` and
`waitpid()`, compare the behavior of both functions, and understand zombie process
handling using proper synchronization techniques.

---

## What We Did

### Part 1 – Multiple Child Processes

- Created a parent process that generates **three child processes** using `fork()`.
- Each child process displays its **Process ID (PID)**.
- The child processes execute independently and terminate after their execution.
- The parent process uses `wait()` to wait for **any one child process** to complete.
- The parent then uses `waitpid()` to specifically wait for **child 3**.
- Finally, the parent waits for the remaining child processes to complete.

### Part 2 – Zombie Process Handling

- Created a parent and child process.
- The child process terminates after completing its execution.
- The parent process uses `wait()` to collect the child's termination status.
- This demonstrates proper **parent-child process synchronization**.
- The process behavior can be investigated using Linux process-monitoring commands such as
  `ps`.

---

## Process Concepts

### Parent Process

The process that creates another process using `fork()` is called the **parent process**.

### Child Process

The new process created by the parent using `fork()` is called the **child process**.

### Process ID (PID)

Every running process in Linux is assigned a unique **Process ID (PID)**.

### Process Synchronization

Process synchronization ensures that the parent and child processes coordinate their
execution and completion properly.

### wait()

`wait()` makes the parent process wait until **any one of its child processes terminates**.

### waitpid()

`waitpid()` allows the parent to wait for a **specific child process** using its PID.

### Zombie Process

A zombie process is a child process that has terminated, but its parent has not yet collected
its termination status.

Using `wait()` or `waitpid()` allows the parent to collect the child's status and prevents
the terminated child from remaining as a zombie.

---

## wait() vs waitpid()

| Function | Behavior |
|----------|----------|
| `wait()` | Waits for any one child process to terminate. |
| `waitpid()` | Waits for a specific child process using its PID. |

---

## Compilation and Execution

### Multiple Child Process Program

```bash
gcc waitex.c
./a.out
Zombie Process Program
gcc Zombie.c
./a.out
Output
1. wait() and waitpid() Output
manu@Manasvi:~$ gcc waitex.c
manu@Manasvi:~$ ./a.out
child 2 pid = 3152
child 1 pid = 3151
child 3 pid = 3153
parent: Any one child complete with wait()
parent: child 3 completes with waitpid()
all the childs completed
manu@Manasvi:~$
2. Zombie Process Output
manu@Manasvi:~$ gcc Zombie.c
manu@Manasvi:~$ ./a.out
parent process 7000
child process 7001
Parent process completed
manu@Manasvi:~$
Observations
Three child processes were successfully created.
The child processes received different PIDs: 3152, 3151, and 3153.
The order in which child processes printed their PIDs was not fixed.
wait() was used to synchronize the parent with any child process.
waitpid() was used to specifically synchronize with child 3.
The parent successfully waited for the child processes to complete.
The second program demonstrated parent-child synchronization using wait().
Proper synchronization allows the parent to collect the child's termination status.
This prevents terminated child processes from remaining as zombies.
Result

Multiple child processes were successfully created and synchronized using wait() and
waitpid(). The behavior of both functions was observed and compared. Parent-child
synchronization was also demonstrated for handling terminated child processes and preventing
zombie processes.

Files
Practical-4/
│
├── waitex.c
├── Zombie.c
└── README.md
arey one single readme file ivvu ra
# OSSP – Practical 4

## Process Synchronization using `wait()` and `waitpid()` and Zombie Process Handling

### Aim
To create multiple child processes and synchronize their completion using `wait()` and `waitpid()`, compare their behavior, and understand zombie process handling using proper synchronization.

### What We Did

A parent process was created to generate three child processes using `fork()`. Each child process displays its Process ID (PID) and terminates after its execution.

The parent process:
- Uses `wait()` to wait for any child process to complete.
- Uses `waitpid()` to specifically wait for child 3.
- Waits for the remaining child processes to complete.

A separate parent-child process experiment was also performed to demonstrate proper synchronization and zombie process handling.

### Process Concepts

**Parent Process:** The process that creates another process using `fork()`.

**Child Process:** The process created by the parent using `fork()`.

**PID:** A unique Process ID assigned to every process in Linux.

**Process Synchronization:** Coordination between processes to ensure their execution and completion happen properly.

**`wait()`:** Waits for any one child process to terminate.

**`waitpid()`:** Waits for a specific child process using its PID.

**Zombie Process:** A terminated child process whose exit status has not yet been collected by its parent.

### Compilation and Execution

```bash
gcc waitex.c
./a.out

gcc Zombie.c
./a.out
Output – Multiple Child Processes
manu@Manasvi:~$ gcc waitex.c
manu@Manasvi:~$ ./a.out
child 2 pid = 3152
child 1 pid = 3151
child 3 pid = 3153
parent: Any one child complete with wait()
parent: child 3 completes with waitpid()
all the childs completed
manu@Manasvi:~$
Output – Zombie Process Handling
manu@Manasvi:~$ gcc Zombie.c
manu@Manasvi:~$ ./a.out
parent process 7000
child process 7001
Parent process completed
manu@Manasvi:~$
Observations
Three child processes were successfully created.
The child processes received PIDs 3152, 3151, and 3153.
The order of child execution can vary because process scheduling is handled by the OS.
wait() was used to synchronize with any child process.
waitpid() was used to specifically synchronize with child 3.
The parent successfully waited for the child processes to complete.
Proper synchronization allows the parent to collect the child's termination status.
The parent-child process experiment demonstrated proper process synchronization and zombie-process handling.
wait() vs waitpid()
Function	Behavior
wait()	Waits for any one child process to terminate.
waitpid()	Waits for a specific child process using its PID.
Result

Multiple child processes were successfully created and synchronized using wait() and waitpid(). The behavior of both functions was observed and compared. Parent-child synchronization and zombie process handling were also demonstrated successfully.

i wanna copy paste one dic
# OSSP – Practical 4

## Process Synchronization using wait() and waitpid() and Zombie Process Handling

### Aim
To create multiple child processes and synchronize their completion using `wait()` and `waitpid()`, compare their behavior, and understand zombie process handling using proper synchronization.

### What We Did
A parent process was created to generate three child processes using `fork()`. Each child process displays its Process ID (PID) and terminates after its execution.

The parent process:
- Uses `wait()` to wait for any child process to complete.
- Uses `waitpid()` to specifically wait for child 3.
- Waits for the remaining child processes to complete.

A separate parent-child process experiment was also performed to demonstrate proper synchronization and zombie process handling.

### Process Concepts

**Parent Process:** The process that creates another process using `fork()`.

**Child Process:** The process created by the parent using `fork()`.

**PID:** A unique Process ID assigned to every process in Linux.

**Process Synchronization:** Coordination between processes to ensure their execution and completion happen properly.

**`wait()`:** Waits for any one child process to terminate.

**`waitpid()`:** Waits for a specific child process using its PID.

**Zombie Process:** A terminated child process whose exit status has not yet been collected by its parent.

### Compilation and Execution

```bash
gcc waitex.c
./a.out

gcc Zombie.c
./a.out
Output – Multiple Child Processes
manu@Manasvi:~$ gcc waitex.c
manu@Manasvi:~$ ./a.out
child 2 pid = 3152
child 1 pid = 3151
child 3 pid = 3153
parent: Any one child complete with wait()
parent: child 3 completes with waitpid()
all the childs completed
manu@Manasvi:~$
Output – Zombie Process Handling
manu@Manasvi:~$ gcc Zombie.c
manu@Manasvi:~$ ./a.out
parent process 7000
child process 7001
Parent process completed
manu@Manasvi:~$
Observations
Three child processes were successfully created.
The child processes received PIDs 3152, 3151, and 3153.
The order of child execution can vary because process scheduling is handled by the OS.
wait() was used to synchronize with any child process.
waitpid() was used to specifically synchronize with child 3.
The parent successfully waited for the child processes to complete.
Proper synchronization allows the parent to collect the child's termination status.
The parent-child process experiment demonstrated proper process synchronization and zombie-process handling.
wait() vs waitpid()
Function	Behavior
wait()	Waits for any one child process to terminate.
waitpid()	Waits for a specific child process using its PID.
Result

Multiple child processes were successfully created and synchronized using wait() and waitpid(). The behavior of both functions was observed and compared. Parent-child synchronization and zombie process handling were also demonstrated successfully.

```bash
gcc waitex.c
parent: Any one child complete with wait()
parent: child 3 completes with waitpid()
all the childs completed

./a.out

gcc Zombie.c
./a.out
