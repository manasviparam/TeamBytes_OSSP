# OSSP – Skill 1 — README

**Skill 1:** Install Linux VM, Configure GCC, Create Project Structure, Compile a First C Program & Explore Processes (fork/exec)
*(See `OSSP_Skill_1.pdf` for the full screenshot walkthrough.)*

---

## Aim
To set up a Linux environment (WSL + Ubuntu) on Windows, configure the GCC C compiler, create a basic C project structure, compile and run a first C program, and explore how processes work using `fork()`, `exec()`, the process tree, and system-call tracing.

## Objectives
- Install a Linux VM (WSL + Ubuntu) on Windows.
- Configure the GCC compiler using `build-essential`.
- Verify that the compiler is installed and working.
- Create a clean project structure (`src`, `include`, `obj`).
- Write, compile, and run a simple C program.
- Understand the basic architecture of a shell.
- Create a child process with `fork()` and run a command with the `exec()` family.
- Observe the parent–child relationship using process IDs (PIDs).
- Inspect the process tree with `pstree`.
- Trace the system calls a program makes with `strace`.

## What We Did (Steps)
1. Opened **Windows PowerShell** as Administrator.
2. Installed WSL and Ubuntu with `wsl --install`, then restarted the PC.
3. On first launch of Ubuntu, created a Linux **username** (`manu`) and **password**.
4. Refreshed the package lists with `sudo apt update`.
5. Installed the GCC compiler with `sudo apt install build-essential`.
6. Verified the compiler with `gcc --version` (GCC 15.2.0).
7. Created a project folder `ossp_shell` with `src`, `include`, and `obj` subfolders.
8. Wrote a simple C program in `src/hello.c` using the **nano** editor.
9. Compiled it directly with `gcc src/hello.c` and ran it with `./a.out`.
10. Created a **Makefile** and built/ran the program with `make` and `./hello`.
11. Wrote `forkexec.c` — it uses `fork()` to create a child process; the child runs `ls` with `execlp()` while the parent `wait()`s. Compiled with `gcc forkexec.c` and ran `./a.out`.
12. Observed the parent and child **PIDs** in the output (child PID 1622, parent PID 1621).
13. Inspected the **process tree** with `pstree`.
14. Traced the program's **system calls** with `strace ./a.out` (showing `clone`, `execve`, `wait4`, `write`).

## Commands Used

| Command | What it does (one line) |
|---|---|
| `wsl --install` | Installs Windows Subsystem for Linux together with Ubuntu. |
| `sudo apt update` | Refreshes the list of available packages and their versions. |
| `sudo apt install build-essential` | Installs GCC and the core tools needed to compile C/C++ programs. |
| `gcc --version` | Displays the installed GCC compiler version (confirms it works). |
| `mkdir` | Creates a new directory (folder). |
| `cd` | Moves into a directory. |
| `ls` | Lists the files and folders in the current directory. |
| `nano` | Opens the nano text editor to create or edit a file. |
| `gcc src/hello.c` | Compiles the C source file (produces `a.out` by default). |
| `./a.out` | Runs the compiled program. |
| `make` | Builds the program using the rule defined in the Makefile. |
| `./hello` | Runs the program built by the Makefile. |
| `gcc forkexec.c` | Compiles the fork/exec program (produces `a.out`). |
| `pstree` | Shows all running processes as a tree (which process started which). |
| `strace ./a.out` | Runs the program and prints every system call it makes. |

## Process Functions Used (in forkexec.c)

| Function | What it does (one line) |
|---|---|
| `fork()` | Creates a new child process; returns `0` to the child and the child's PID to the parent. |
| `execlp()` | Replaces the current process with another program (here, `ls`). |
| `wait(NULL)` | Makes the parent pause until its child process finishes. |
| `getpid()` | Returns the current process's ID (PID). |
| `getppid()` | Returns the parent process's ID. |

## What We Understood
- Windows can run a full Linux environment through **WSL**, without dual-booting or a separate machine.
- `build-essential` bundles **GCC** and the tools required to compile C programs on Linux.
- A **project structure** (`src`/`include`/`obj`) keeps source files, header files, and compiled object files organized.
- A C program must be **compiled** into an executable before it can run; `gcc` does this and produces `a.out` by default (or a named output with `-o`).
- A **Makefile** automates compilation — instead of typing the full `gcc` command each time, `make` reads the build rule and runs it.
- A **shell** works in a loop: it reads a command, parses it, creates a child process with `fork()`, runs the command with `exec()`, and the parent `wait()`s until the child finishes before showing the prompt again.
- **Process abstraction:** every running program is a **process** with its own unique **PID**; `fork()` creates a new one.
- **`fork()` returns twice** — `0` inside the child and the child's PID inside the parent — which is how one program splits into a parent and a child.
- **`exec()`** replaces a process's program with a new one, so the child can run a command like `ls` in place of itself.
- The **process tree** (`pstree`) shows that every process descends from `systemd`, the first process started at boot.
- **`strace`** reveals the system calls behind the scenes: `clone` for `fork()`, `execve` for `exec()`, `wait4` for `wait()`, and `write` for `printf`.
