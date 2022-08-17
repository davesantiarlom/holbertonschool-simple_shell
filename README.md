# holbertonschool-simple_shell :bulb:

Simple shell is a UNIX command interpreter that replicates core functionalities of the sh shell. This project was developed as part of the third month curriculum at Holberton School

### Resources
Read or watch:

 * [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)
 * [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
 * [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
 * [Everything you need to know to start coding your own shell concept page](https://intranet.hbtn.io/concepts/900)
 
**man or help:**

sh (Run sh as well)

### Testing

Interactive Mode - To call the shell in its interactive mode it must be called as follows:

      ./hsh

After this invocation the prompt will be printed and the user will be able to enter command line arguments.

Non-Interactive Mode - To call the shell in its non-interactive mode you first call the command and then pipe it to the shell as follows:

      [Command] [Command Options] [Arguments] ... | ./hsh

After this invocation the shell will exit and return to the terminal that called it.

### Flowchart :bulb:

Let us consider a flowchart that will help us to understand the operation of the program in a logical way.

[![Whats-App-Image-2022-08-16-at-6-18-28-PM.jpg](https://i.postimg.cc/4d5zcbnN/Whats-App-Image-2022-08-16-at-6-18-28-PM.jpg)](https://postimg.cc/VrJrQtj3)

### Installation and compilation :bulb:

* Clone this repo - ```git@github.com:davesantiarlom/holbertonschool-simple_shell.git```
* Compile - ```gcc -Wall -Werror -Wextra -pedantic *.c -o hsh```
* To run interactve - ``` ./hsh ```
* If you want to debugg - ```valgrind --leak-check=full ./hsh```

## List of allowed functions and system calls used

  * execve(): is used for the execution of the program that is referred to by pathname
  * exit(): is used to break out of a loop
  * fflush(): is used to immediately flush out the contents of an output stream
  * fork(): is used to create a new process. This newly created process is known as child process
  * free(): allows you to release or deallocate the memory blocks which are previously allocated by calloc(), malloc() or realloc() functions
  * getline(): accepts a string from the input stream as an input
  * isatty(): tests whether fildes, an open file descriptor, is associated with a terminal device
  * malloc(): is used to dynamically allocate a single large block of memory with the specified size
  * perror(): function displays the description of the error that corresponds to the error code stored in the system variable errno
  * stat(): is a system struct that is defined to store information about files
  * strtok(): splits s1 into a series of tokens using the delimiter s2
  * waitpid(): suspends execution of the current process until a child specified by the pid argument has been terminated
  
## Own String Functions

  * _strcmp(): A funtion that compares two strings
  * _strlen(): A function that finds the length of the string
  * *_strcpy(): A function that copies a string to another string
  * *_strcat(): A function that concatenates two strings
  * _atoi(): A function that converts string to integer

## Examples

Here are some examples of the usage of the Shell:

* Example: ls

      $ ls -l
      total 68
      -rw-r--r-- 1 root root   237 Aug 13 16:56 AUTHORS
      -rw-r--r-- 1 root root   953 Aug 16 19:43 README.md
      -rw-r--r-- 1 root root   749 Aug 14 21:49 create_child.c
      -rw-r--r-- 1 root root   984 Aug 16 19:36 execute.c
      -rw-r--r-- 1 root root   665 Aug 14 22:14 free_memory.c
      -rw-r--r-- 1 root root  1683 Aug 14 22:06 functions_string.c
      -rwxr-xr-x 1 root root 18096 Aug 16 19:57 hsh
      -rw-r--r-- 1 root root  1148 Aug 16 18:34 main.c
      -rw-r--r-- 1 root root   549 Aug 16 19:39 messagerror.c
      -rw-r--r-- 1 root root   531 Aug 16 19:36 path.c
      -rw-r--r-- 1 root root   351 Aug 14 21:52 print_env.c
      -rw-r--r-- 1 root root   786 Aug 16 19:37 shell.h
      -rw-r--r-- 1 root root   909 Aug 16 19:39 split.c
  

* Example: pwd

      $ pwd
      /root/holbertonschool-simple_shell
    

* Example: ENV

      $ env
      SHELL=/bin/bash
      SUDO_GID=1000
      SUDO_COMMAND=/bin/bash
      SUDO_USER=davesantiarlom
      PWD=/root/holbertonschool-simple_shell
      LOGNAME=root
      MOTD_SHOWN=update-motd
      HOME=/root
      LANG=C.UTF-8
      ...

* Example: echo

      $ echo Hello World
      Hello World

For More Information About the proyect check the man page:

      Username@Linux-Docker:~$ man ./man_simple_shell

### Authors :bulb:

[David Santiago Arias](https://github.com/davesantiarlom) - Github

[Avelino Carvajal](https://github.com/AvelinoC5) - Github
