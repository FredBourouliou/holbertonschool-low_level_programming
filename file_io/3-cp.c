#include "main.h"
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * error_handler - handles error messages and exit codes
 * @exit_code: exit code
 * @message: error message
 * @filename: name of the file
 */
void error_handler(int exit_code, const char *message, const char *filename)
{
	dprintf(STDERR_FILENO, message, filename);
	exit(exit_code);
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
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];
	const char *file_from, *file_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = argv[1];
	file_to = argv[2];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		error_handler(98, "Error: Can't read from file %s\n", file_from);

	bytes_read = read(fd_from, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		close(fd_from);
		error_handler(98, "Error: Can't read from file %s\n", file_from);
	}

	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_handler(99, "Error: Can't write to %s\n", file_to);
	}

	bytes_written = write(fd_to, buffer, bytes_read);
	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		close(fd_from);
		close(fd_to);
		error_handler(99, "Error: Can't write to %s\n", file_to);
	}

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			close(fd_from);
			close(fd_to);
			error_handler(99, "Error: Can't write to %s\n", file_to);
		}
	}

	if (bytes_read == -1)
	{
		close(fd_from);
		close(fd_to);
		error_handler(98, "Error: Can't read from file %s\n", file_from);
	}

	if (close(fd_from) == -1)
	{
		close(fd_to);
		error_handler(100, "Error: Can't close fd %d\n", file_from);
	}
	if (close(fd_to) == -1)
		error_handler(100, "Error: Can't close fd %d\n", file_to);

	return (0);
}
