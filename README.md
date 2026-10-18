# Holberton School — Low-level programming in C

Coursework from Holberton School's software engineering program (2024–2026).

## Projects

- `hello_world` — compilation steps (preprocessor, compiler, assembler) and first programs
- `variables_if_else_while` — variables, conditionals and loops
- `functions_nested_loops`, `more_functions_nested_loops` — functions, nested loops, `_putchar` output
- `pointers_arrays_strings` — pointers, arrays and re-implemented string functions
- `recursion` — recursive functions (strings, power, square root, primes, palindromes)
- `malloc_free`, `more_malloc_free` — dynamic memory allocation
- `argc_argv` — command-line arguments
- `structures_typedef` — structures and `typedef`
- `function_pointers` — function pointers and a small calculator
- `variadic_functions` — variadic functions with `stdarg.h`
- `singly_linked_lists`, `doubly_linked_lists` — linked list operations
- `bit_manipulation` — binary conversion, bit operations, endianness
- `file_io` — file I/O with system calls, `cp` and an ELF header reader

## Build

C (gnu89), Betty style. Each folder pairs task files with `*-main.c` test files:

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c 0-main.c 0-puts_recursion.c -o 0-puts_recursion
```
