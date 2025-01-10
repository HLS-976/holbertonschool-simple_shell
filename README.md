

![logo](https://i.imgur.com/02Avpeu.png)
    
## ∭ Synopsis
This simple shell project was made as part of a Holberton School project to create a command interpreter that mimics the behavior of a Unix shell.

## 📝 Description
What is a shell?

A shell allows the user to interact with the operating system by accepting commands entered by the user from the keyboard, checking if the user's input is correct, and executing it.
The simple shell is a customized and minimalist version that mimics the behavior of the Unix shell.

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


### 👀 Flowchart
![Flowchart](https://i.imgur.com/lNtw06X.png)

## ⌨️ Installation and run

To install and configure the project, follow the steps below:

1. Clone the repository:

    `git clone https://github.com/HLS-976/holbertonschool-simple_shell.git`

2. Compile the project:

    `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o dsh`

3. Run the shell:
    - Interactive mode : `./dsh`
    - Non-interactive mode : `echo "...." | ./dsh` 

## 💻 Demonstration

- Simple command execution like :

| Commands                   | Description                                      | 
| :--------                  | :----------------------------------------        |
| `/bin/ls or ls`            |  *List the contents of curent directory*         |
| `/bin/pwd or pwd`          |  *Display the absolute path of current directory*|
| `CTRL+C`                   |  *Does not interrupt the simple shell*           |
| `exit or CTRL+D`           |  *Stop and exit the program*                     |
| `arguments`                |  *Command arguments to customize search results* |

`Input/output redirection` *handles non-interactive and interactive mode* 


## 💻Demonstrations 
```
(shell)-$ /bin/ls -l
total 72
-rw-r--r-- 1 root root   160 Jan  9 16:21 AUTHORS
-rw-r--r-- 1 root root  3858 Jan 10 11:20 README.md
-rw-r--r-- 1 root root   533 Jan  8 16:35 _getenv.c
-rw-r--r-- 1 root root   621 Dec 27 16:15 count_tokens.c
-rwxr-xr-x 1 root root 17832 Jan 10 12:23 dsh
-rw-r--r-- 1 root root  1899 Jan 10 11:25 execution.c
-rw-r--r-- 1 root root   856 Jan  8 16:35 find_command_in_path.c
-rw-r--r-- 1 root root   217 Jan  8 09:19 is_interactive.c
-rw-r--r-- 1 root root   625 Jan 10 11:21 main.h
-rw-r--r-- 1 root root  2240 Jan  9 16:19 man_1_simple_shell
-rw-r--r-- 1 root root   205 Jan  9 16:19 print_env.c
-rw-r--r-- 1 root root  2545 Jan  9 16:32 shell.c
-rw-r--r-- 1 root root   189 Jan  9 16:32 signal_handler.c
-rw-r--r-- 1 root root   873 Jan  8 09:19 tokenize_line.c

(shell)-$ ls
AUTHORS    _getenv.c       dsh          find_command_in_path.c  main.h              print_env.c  signal_handler.c
README.md  count_tokens.c  execution.c  is_interactive.c        man_1_simple_shell  shell.c      tokenize_line.c

(shell)-$/bin/pwd
/root/holbertonschool-simple_shell

root@Vidad:~/holbertonschool-simple_shell# ./dsh
(shell)-$ ^C
(shell)-$ exit

(shell)-$ exit
```

### This code has been verified using Valgrind (*Valgrind checks for possible memory leaks*)
### `valgrind ./dsh`
```
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

## Use man in shell
*To run the man page on the terminal* - `man ./man_1_simple_shell`
 
### Overview [👉 man_1_simple_shell](https://github.com/HLS-976/holbertonschool-simple_shell/blob/main/man_1_simple_shell)

## Bugs

### *No known bugs exists within the program as of this writing*

- If you encounter any bugs or issues, please report them via l'[issue tracker](https://github.com/HLS-976/holbertonschool-simple_shell/issues)

## Project carried out by

![](https://flat-badgen.vercel.app/badge/icon/github?icon=github&label)

- Hilliass Soumahill [@HLS-976](https://github.com/HLS-976/holbertonschool-simple_shell)

- David Tolza [@VidadTol](https://www.github.com/VidadTol)

## License

This project is licensed under the MIT License. See the LICENSE file for more details.

![logo](https://i.imgur.com/J1oVLId.jpeg)

