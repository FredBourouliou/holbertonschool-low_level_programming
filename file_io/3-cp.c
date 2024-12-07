#include "main.h"
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - prints error message and exits
 * @code: exit code
 * @msg: error message
 * @arg: argument for message
 */
void error_exit(int code, char *msg, int arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * error_exit_str - prints error message with string arg and exits
 * @code: exit code
 * @msg: error message
 * @arg: string argument for message
 */
void error_exit_str(int code, char *msg, char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * copy_file - copies file content
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @src: source filename
 * @dest: destination filename
 */
void copy_file(int fd_from, int fd_to, char *src, char *dest)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	bytes_read = read(fd_from, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		close(fd_from);
		error_exit_str(98, "Error: Can't read from file %s\n", src);
	}

	do {
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			close(fd_from);
			close(fd_to);
			error_exit_str(99, "Error: Can't write to %s\n", dest);
		}
	} while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0);

	if (bytes_read == -1)
	{
		close(fd_from);
		close(fd_to);
		error_exit_str(98, "Error: Can't read from file %s\n", src);
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

	if (argc != 3)
		error_exit_str(97, "Usage: cp file_from file_to\n", "");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit_str(98, "Error: Can't read from file %s\n", argv[1]);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit_str(99, "Error: Can't write to %s\n", argv[2]);
	}

	copy_file(fd_from, fd_to, argv[1], argv[2]);

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd %d\n", fd_from);
	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd %d\n", fd_to);

	return (0);
}
