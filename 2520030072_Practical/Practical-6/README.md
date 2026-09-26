# Practical 6 – Named Pipes (FIFO) and POSIX Signal Handling

This practical demonstrates two core Linux/UNIX systems-programming concepts:

1. **Inter-process communication using Named Pipes (FIFOs)**
2. **Asynchronous event handling using POSIX signals**

---

## 📁 Files

| File | Description |
|---|---|
| `Server.c` | Creates the FIFO, waits for a client message, prints it, and sends a response back. |
| `Client.c` | Sends a message to the server through the FIFO and prints the server's response. |
| `Signal.c` | Registers handlers for `SIGINT`, `SIGTERM`, and `SIGUSR1` and exits after all three are received. |

---

## Question 1: FIFO Client–Server Communication

### Objective
Create a client-server application using Named Pipes (FIFOs). The client sends messages and the server processes and responds to them. Analyze FIFO behavior when multiple clients communicate simultaneously.

### What We Did
We created a simple client-server communication system using a named pipe called **`myfifo`**. The server:
- Creates the FIFO if it doesn't already exist.
- Opens it for reading and blocks until a client writes to it.
- Reads the client's message, prints it, and sends a response back through a response channel.

The client:
- Opens the FIFO for writing.
- Sends the message **"Hello Server"**.
- Reads and prints the server's response.

### Commands Used
- **Compile:** `gcc Server.c -o server` and `gcc Client.c -o client`
- **Run:** `./server` in one terminal, `./client` in another (separate terminals)

### Sample Output

**Server terminal**
```
Server started...
Waiting for client message...
Client message: Hello Server
Server response sent
```

**Client terminal**
```
Client started
Message sent to server
Server response: Message processed by server
```

### Observation
- A FIFO (named pipe) allows two unrelated processes to exchange data through the filesystem.
- The server blocks on read until a client writes to the FIFO — this is a synchronizing, blocking form of IPC.
- When **multiple clients** write to the same FIFO, the server processes messages **one at a time**, in the order they arrive; the FIFO does not multiplex or tag messages by client, so all clients share the same communication channel and access is effectively serialized.

---

## Question 2: POSIX Signal Handling

### Objective
Create a POSIX signal handling program that captures `SIGINT`, `SIGTERM`, and `SIGUSR1`. Demonstrate asynchronous event handling and explain the role of signal handlers.

### What We Did
We registered custom handlers for `SIGINT`, `SIGTERM`, and `SIGUSR1`. The program displays its process ID and then idles, waiting for signals sent from another terminal using the `kill` command. Each handler prints which signal was received. A counter tracks how many distinct signals have arrived; once all three are received, the program prints a final message and exits.

### Commands Used
- **Compile:** `gcc Signal.c -o signal_demo`
- **Run:** `./signal_demo`
- **Send signals (from another terminal, using the printed PID):**
  - `kill -SIGUSR1 PID`
  - `kill -SIGTERM PID`
  - `kill -SIGINT PID`

### Sample Output
```
Process ID = 4397
Waiting for signals...
SIGUSR1 received
SIGTERM received
SIGINT received
All signals received. Exiting...
```

### Observation
- Signal handling allows a running process to respond to **asynchronous events** without polling.
- The process suspends execution until any signal arrives, at which point control transfers to the registered handler.
- Each handler identifies which signal fired and performs the appropriate action; after all three signals have been received, the program terminates cleanly.

---

## Result
Successfully implemented:
1. FIFO-based client-server communication (with observations on multi-client behavior), and
2. POSIX signal handling for `SIGINT`, `SIGTERM`, and `SIGUSR1`,

both verified through terminal execution.
