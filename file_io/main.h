#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* ELF Header Definitions */
#define EI_NIDENT 16

/* e_ident[] indexes */
#define EI_MAG0    0
#define EI_MAG1    1
#define EI_MAG2    2
#define EI_MAG3    3
#define EI_CLASS   4
#define EI_DATA    5
#define EI_VERSION 6
#define EI_OSABI   7
#define EI_ABIVERSION 8

/* ELF Magic Numbers */
#define ELFMAG0 0x7f
#define ELFMAG1 'E'
#define ELFMAG2 'L'
#define ELFMAG3 'F'

/* ELF Classes */
#define ELFCLASSNONE 0
#define ELFCLASS32   1
#define ELFCLASS64   2

/* ELF Data Encodings */
#define ELFDATANONE  0
#define ELFDATA2LSB  1
#define ELFDATA2MSB  2

/* ELF Version */
#define EV_NONE    0
#define EV_CURRENT 1

/* OS/ABI Values */
#define ELFOSABI_NONE     0
#define ELFOSABI_HPUX     1
#define ELFOSABI_NETBSD   2
#define ELFOSABI_LINUX    3
#define ELFOSABI_SOLARIS  6
#define ELFOSABI_AIX      7
#define ELFOSABI_IRIX     8
#define ELFOSABI_FREEBSD  9
#define ELFOSABI_TRU64    10

/* Object File Types */
#define ET_NONE   0
#define ET_REL    1
#define ET_EXEC   2
#define ET_DYN    3
#define ET_CORE   4

typedef struct {
    unsigned char e_ident[EI_NIDENT];
    unsigned short e_type;
    unsigned short e_machine;
    unsigned int   e_version;
    unsigned long  e_entry;
    unsigned long  e_phoff;
    unsigned long  e_shoff;
    unsigned int   e_flags;
    unsigned short e_ehsize;
    unsigned short e_phentsize;
    unsigned short e_phnum;
    unsigned short e_shentsize;
    unsigned short e_shnum;
    unsigned short e_shstrndx;
} Elf64_Ehdr;

/* Function prototypes */
void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

#endif /* MAIN_H */
