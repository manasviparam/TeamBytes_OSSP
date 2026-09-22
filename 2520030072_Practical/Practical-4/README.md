# OSSP – Practical 4

## Aim
To create multiple child processes and synchronize their completion using `wait()` and `waitpid()`, compare their behavior, and understand zombie processes and their prevention.

## What We Did
- Created multiple child processes using `fork()`.
- Used `wait()` to wait for any child process to complete.
- Used `waitpid()` to wait for a specific child process.
- Created a zombie process scenario.
- Observed parent and child process behavior.
- Used proper synchronization to prevent zombie processes.

## Process
1. Parent process creates multiple child processes.
2. Child processes execute independently.
3. `wait()` waits for any completed child.
4. `waitpid()` waits for a specific child.
5. A zombie process was demonstrated.
6. Proper synchronization was used to prevent the zombie condition.

## Concepts Used
- `fork()`
- Parent and child processes
- Process synchronization
- `wait()`
- `waitpid()`
- Zombie processes
- Process termination and exit status

## Comparison

| Function | Behavior |
|---|---|
| `wait()` | Waits for any child process to complete |
| `waitpid()` | Waits for a specific child process |


## Compilation and Execution:

- gcc waitex.c
- ./a.out

- gcc Zombie.c
- ./a.out


## Output:

child 2 pid = 3152
child 1 pid = 3151
child 3 pid = 3153
parent: Any one child complete with wait()
parent: child 3 completes with waitpid()
all the childs completed

parent process 7000
child process 7001
Parent process completed

## What We Learnt / Understood:

How a parent process creates and manages child processes.
Difference between wait() and waitpid().
How process synchronization works.
How a zombie process is created.
How proper synchronization prevents zombie processes.


## Observations:

wait() can collect the termination status of any completed child.
waitpid() can specifically wait for a selected child.
Without proper synchronization, a terminated child can remain as a zombie.
Proper synchronization prevents zombie processes.

## Result:
The practical demonstrated process synchronization using wait() and waitpid() and showed how zombie processes can be identified and prevented.
