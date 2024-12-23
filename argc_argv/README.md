# C - argc, argv

A collection of C programs demonstrating command-line argument handling.

## Author
Frédéric Bourouliou

## Programs Description

### 0. What's my name
* File: `0-whatsmyname.c`
* Description: Program that prints its own name.
* Usage: `./mynameis`

### 1. Number of arguments
* File: `1-args.c`
* Description: Program that prints the number of arguments passed to it.
* Usage: `./args [arguments...]`

### 2. Arguments
* File: `2-args.c`
* Description: Program that prints all arguments it receives, one per line.
* Usage: `./args [arguments...]`

### 3. Multiplication
* File: `3-mul.c`
* Description: Program that multiplies two numbers passed as arguments.
* Usage: `./mul num1 num2`

### 4. Addition
* File: `4-add.c`
* Description: Program that adds positive numbers passed as arguments.
* Usage: `./add num1 num2 ...`

### 5. Minimal Number of Coins for Change (Advanced)
* File: `100-change.c`
* Description: Program that calculates the minimum number of coins needed to make change for a given amount.
* Usage: `./change cents`
* Available coin denominations: 25, 10, 5, 2, and 1 cent

## Flowchart for Change Program
```mermaid
flowchart TD
    A[Start] --> B{Check argc == 2}
    B -->|No| C[Print Error]
    C --> D[Return 1]
    B -->|Yes| E[Convert argv[1] to int]
    E --> F{Is amount negative?}
    F -->|Yes| G[Print 0]
    G --> H[Return 0]
    F -->|No| I[Initialize coins = 0]
    I --> J{Is amount > 0?}
    J -->|Yes| K{amount >= 25?}
    K -->|Yes| L[Subtract 25]
    K -->|No| M{amount >= 10?}
    M -->|Yes| N[Subtract 10]
    M -->|No| O{amount >= 5?}
    O -->|Yes| P[Subtract 5]
    O -->|No| Q{amount >= 2?}
    Q -->|Yes| R[Subtract 2]
    Q -->|No| S[Subtract 1]
    L & N & P & R & S --> T[Increment coins]
    T --> J
    J -->|No| U[Print coins]
    U --> V[Return 0]
```

## Compilation
All programs can be compiled using:
```bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 [filename.c] -o [output]
```
