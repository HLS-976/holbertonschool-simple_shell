

![logo](https://i.imgur.com/02Avpeu.png)

## Synopsis ✏️

A shell is a program that acts as an interface between the user and the operating system.

## Description 

A shell allows the user to interact with the operating system by accepting commands entered by the user from the keyboard, checking whether the user's input is correct, and executing it.

## Introduction

This simple shell project was made as part of a training to create a command interpreter that mimics the operation of a Unix shell. The shell allows you to execute commands entered by the user, manage processes and interact with the operating system.
    
## Requirements

### *General*

- Allowed editors: vi, vim, emacs
- Compiled on Ubuntu 24.04.1 LTS*
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to (why?)
- Function prototypes are in the header file main.h

## Fonctionnalités

- Simple command execution
- Path management
- Built-in commands: ls, ls -l, pwd, exit, CTRL D,
- Input/output redirection

### Flowchart
![Flowchart](https://i.imgur.com/QLS4qHH.png)

## Installation

To install and configure the project, follow the steps below:

1. Clone the repository:

    `git clone https://github.com/HLS-976/holbertonschool-simple_shell.git`

2. Change to the project directory:

    `ls holbertonschool-simple_shell`

3. Compile the project:

    `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell`

4. Run the shell:

    `./simple_shell`


## Demonstrations /bin/ls -l, ls, pwd, exit, valgrind,
```
(shell)-$/bin/ls -l
total 60
-rw-r--r-- 1 root root   140 Dec 26 11:45 AUTHORS
-rw-r--r-- 1 root root  3030 Dec 26 11:45 README.md
-rw-r--r-- 1 root root   429 Dec 26 15:46 child_exit.c
-rw-r--r-- 1 root root   613 Dec 20 15:05 count_tokens.c
-rw-r--r-- 1 root root  1424 Dec 26 12:02 execution.c
-rw-r--r-- 1 root root   520 Dec 26 15:47 main.h
-rw-r--r-- 1 root root  2136 Dec 26 11:45 man_1_simple_shell
-rw-r--r-- 1 root root   540 Dec 20 15:05 read_line.c
-rw-r--r-- 1 root root   900 Dec 26 16:27 shell.c
-rwxr-xr-x 1 root root 16888 Dec 26 16:31 test
-rw-r--r-- 1 root root   742 Dec 20 15:05 tokenize_line.c

(shell)-$/bin/ls
AUTHORS    child_exit.c    execution.c  man_1_simple_shell  shell.c  tokenize_line.c
README.md  count_tokens.c  main.h       read_line.c         test

(shell)-$/bin/pwd
/root/holbertonschool-simple_shell

(shell)-$exit
==2630==
==2630== HEAP SUMMARY:
==2630==     in use at exit: 0 bytes in 0 blocks
==2630==   total heap usage: 14 allocs, 14 frees, 2,518 bytes allocated
==2630==
==2630== All heap blocks were freed -- no leaks are possible
==2630==
==2630== For lists of detected and suppressed errors, rerun with: -s
==2630== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## Compilation

To compile the shell, use the following command:

### `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell`

## Use man in shell

### `man simple_shell`

## Bugs

### *No known bugs exists within the program as of this writing*

- If you encounter any bugs or issues, please report them via l'[issue tracker](https://github.com/HLS-976/holbertonschool-simple_shell)

## Project carried out by

![](https://flat-badgen.vercel.app/badge/icon/github?icon=github&label)

-  Hilliass Soumahill[@HLS-976](https://github.com/HLS-976/holbertonschool-simple_shell)

- David Tolza [@VidadTol](https://www.github.com/VidadTol)

## License

This project is licensed under the MIT License. See the LICENSE file for more details.

```html
![logo](https://i.imgur.com/J1oVLId.jpeg)
```

