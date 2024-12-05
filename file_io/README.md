# C - File I/O

This project covers file input/output operations in C programming using system calls. It includes functions to read, create, and modify files using file descriptors.

## Description

This project contains several functions that demonstrate file operations:

* `read_textfile`: Reads and prints a text file to POSIX standard output
* `create_file`: Creates a file with specific permissions and content
* `append_text_to_file`: Appends text to the end of an existing file
* `cp`: A program that copies the content of one file to another

## Requirements

* All files compiled on Ubuntu 20.04 LTS using gcc
* Compilation flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
* Code follows Betty style guidelines
* No global variables
* Maximum of 5 functions per file
* Only allowed C standard library functions: malloc, free, exit
* Allowed syscalls: read, write, open, close
* All header files are include guarded

## Files Description

* `0-read_textfile.c`: Function that reads a text file and prints it to POSIX standard output
* `1-create_file.c`: Function that creates a file with specific permissions
* `2-append_text_to_file.c`: Function that appends text at the end of a file
* `3-cp.c`: Program that copies the content of a file to another file
* `main.h`: Header file containing all function prototypes
* `_putchar.c`: Function that writes a character to stdout

## Function Prototypes

```c
ssize_t read_
