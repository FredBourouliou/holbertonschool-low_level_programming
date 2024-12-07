#include "main.h"
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * handle_errors - handles error messages and exits
 * @code: exit code
 * @message: error message
 * @arg: argument for error message
 */
void handle_errors(int code, char *message, char *arg)
{
	dprintf(STDERR_FILENO, message, arg);
	exit(code);
}

/**
 * check_args - validates command line arguments
 * @argc: argument count
 * @argv: argument vector
 */
void check_args(int argc, char *argv[])
{
	if (argc != 3)
		handle_errors(97, "Usage: cp file_from file_to\n", "");
}

/**
 * copy_content - copies content between files
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @argv: argument vector for filenames
 */
void copy_content(int fd_from, int fd_to, char *argv[])
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	do {
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			close(fd_from);
			close(fd_to);
			handle_errors(99, "Error: Can't write to %s\n", argv[2]);
		}
	} while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0);

	if (bytes_read == -1)
	{
		close(fd_from);
		close(fd_to);
		handle_errors(98, "Error: Can't read from file %s\n", argv[1]);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;

	check_args(argc, argv);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		handle_errors(98, "Error: Can't read from file %s\n", argv[1]);

	bytes_read = read(fd_from, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		close(fd_from);
		handle_errors(98, "Error: Can't read from file %s\n", argv[1]);
	}

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		handle_errors(99, "Error: Can't write to %s\n", argv[2]);
	}

	copy_content(fd_from, fd_to, argv);

	if (close(fd_from) == -1)
		handle_errors(100, "Error: Can't close fd %d\n", argv[1]);
	if (close(fd_to) == -1)
		handle_errors(100, "Error: Can't close fd %d\n", argv[2]);

	return (0);
}
