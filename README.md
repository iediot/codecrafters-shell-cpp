```
<h1 align="center">Shell Implementation</h1>

<p align="center">
A lightweight interactive Unix shell written in C++.
</p>

<p align="center">
Implements command parsing, pipelines, redirection, history, and tab completion using POSIX system calls.
</p>

<p align="center">
<img src="https://img.shields.io/badge/Linux-grey?logo=linux&logoColor=white">
<img src="https://img.shields.io/badge/C%2B%2B-blue?logo=c%2B%2B&logoColor=white">
<img src="https://img.shields.io/badge/POSIX-darkgreen">
<img src="https://img.shields.io/badge/CMake-orange">
</p>

---

### Overview

This project implements a small Unix-like shell capable of interpreting user commands and executing them using POSIX process APIs.

The shell runs interactively and supports both builtin commands and external programs available in the system PATH.

---

### Features

| Feature | Description |
|---|---|
| Interactive REPL | Continuously reads and executes commands |
| Command parsing | Supports quoting, escaping and argument splitting |
| Builtin commands | Implemented directly in the shell |
| External command execution | Runs programs using fork() and execvp() |
| Pipelines | Connect commands using `|` |
| Output redirection | Supports `>`, `>>`, `1>`, `2>` |
| Command history | Stores previous commands |
| History navigation | Use arrow keys to browse commands |
| Tab completion | Autocomplete commands and files |
| PATH lookup | Searches executables in system PATH |

---

### Builtin Commands

| Command | Description |
|---|---|
| `echo` | Prints arguments to standard output |
| `pwd` | Displays the current working directory |
| `cd` | Changes the current working directory |
| `exit` | Terminates the shell session |
| `type` | Determines whether a command is builtin or an executable |
| `history` | Displays and manages command history |

---

### Command Examples

echo hello world  
pwd  
cd /tmp  
type ls  
history  

---

### Pipelines

Commands can be chained together using pipes.

ls | grep cpp  
cat file.txt | sort | uniq  

The output of one process becomes the input of the next process.

---

### Output Redirection

Redirect command output to files.

echo hello > file.txt  
echo hello >> file.txt  
command 2> error.log  

Supported operators:

| Operator | Behavior |
|---|---|
| `>` | overwrite file |
| `>>` | append to file |
| `1>` | redirect stdout |
| `2>` | redirect stderr |

---

### Command History

The shell stores previously executed commands and allows navigation using arrow keys.

| Key | Action |
|---|---|
| Up arrow | previous command |
| Down arrow | next command |

History can also be written to or loaded from files using the `history` builtin.

history  
history 10  
history -r file  
history -w file  
history -a file  

---

### Tab Completion

Press Tab to autocomplete commands or file names.

The shell attempts completion using:

• builtin commands  
• executables in PATH  
• files in the current directory  

If multiple matches exist, pressing Tab twice shows the available options.

---

### Implementation Details

Key technologies used:

• POSIX process APIs (fork, execvp, wait)  
• terminal control using termios  
• filesystem utilities using std::filesystem  
• directory scanning using dirent  
• file descriptor manipulation with dup2  
• pipes using pipe()  

---

### Example Session

$ pwd  
/home/user  

$ echo hello  
hello  

$ ls | grep main  
main.cpp  

$ history  
    1  pwd  
    2  echo hello  
    3  ls | grep main  

---

### Build

mkdir build  
cd build  
cmake ..  
make  

---

### Run

./your_shell

---

### Project Structure

.
├── src  
│   └── main.cpp  
├── CMakeLists.txt  
└── README.md  

---

### Concepts Demonstrated

• interactive shell design  
• command parsing  
• Unix process creation  
• pipelines and interprocess communication  
• file descriptor manipulation  
• terminal input handling
```
[![progress-banner](https://backend.codecrafters.io/progress/shell/bdf14e8a-708e-455d-87f4-93ddacd99e73)](https://app.codecrafters.io/users/iediot?r=2qF)
