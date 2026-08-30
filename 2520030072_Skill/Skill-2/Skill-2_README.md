# OSSP – Skill 2 — README

**Skill 2:** Build the Main Loop of a Simple Shell (Display Prompt, Read Input, Handle Exit) + Keyboard Input
*(See `OSSP_Skill_2.pdf` for the screenshot walkthrough and control-flow diagram.)*

---

## Aim
To build the main loop of a simple command-line shell in C — one that shows a prompt, reads the command the user types, echoes it back, and exits when the user types `exit`.

## Objectives
**Main loop:** create the main loop · display a prompt · read user input · handle exit conditions · design a control-flow diagram · test the interactive loop.
**Keyboard input:** capture keyboard input · handle backspace · process the Enter key · manage the input buffer · support multi-character commands · test user interaction.

## What We Did (Steps)
1. Went into the Skill 1 project folder: `cd ~/os_lab/ossp_shell`.
2. Created `src/shell.c` in **nano** and wrote the shell's main loop.
3. Inside the loop: displayed a `myshell>` prompt, read a command with `scanf`, checked whether it was `exit`, and echoed it back otherwise.
4. Compiled with `gcc src/shell.c` and ran the program with `./a.out`.
5. Tested it by typing `hello` and `date` (echoed back), then `exit` (which ends the loop).
6. Drew the **control-flow diagram** of the loop.

## Commands Used

| Command | What it does (one line) |
|---|---|
| `nano src/shell.c` | Opens the nano text editor to write/edit the program. |
| `gcc src/shell.c` | Compiles the C program (produces `a.out`). |
| `./a.out` | Runs the compiled shell program. |

## C Functions & Keywords Used

| Item | What it does (one line) |
|---|---|
| `printf` | Prints text/output to the screen. |
| `scanf` | Reads what the user types on the keyboard. |
| `strcmp` | Compares two strings; returns `0` when they are equal. |
| `while (1)` | A loop that repeats forever (our main loop). |
| `if` | Runs code only when a condition is true. |
| `break` | Immediately exits the loop. |
| `char input[100]` | An array (buffer) that stores the typed command. |

## Handling the Enter Key and Backspace
- **Enter key:** Pressing **Enter** marks the end of a command. `scanf("%s", input)` reads characters until it reaches the Enter (or a space), so the Enter key is what tells the program the command is finished and ready to be processed. After that, the loop checks the command and either exits or echoes it.
- **Backspace:** While the user is typing, the terminal runs in its normal (*canonical*) mode, which handles line editing automatically. Pressing **Backspace** deletes the last character *before* the line is sent to the program — so the user can fix typos, and the program receives only the final, corrected command in its input buffer.

## What We Understood
- A **shell** is just a program that runs in a loop: show a prompt, read a command, act on it, and repeat.
- `while(1)` keeps the shell running, and `break` (when the user types `exit`) is what stops it.
- `scanf` reads the keyboard input into a **buffer** (`input[100]`), and pressing **Enter** ends the input.
- `strcmp` lets us compare the typed command against `"exit"` to decide when to quit.
- **Backspace and line editing while typing are provided by the terminal itself**, so a basic shell doesn't need extra code to handle them.
- The **control-flow diagram** captures the loop: prompt → read input → is it `exit`? → (yes: end / no: echo the command and loop back).
