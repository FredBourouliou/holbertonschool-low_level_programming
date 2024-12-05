#include "main.h"

/**
 * read_textfile - reads a text file and prints it to POSIX stdout
 * @filename: name of the file to read
 * @letters: number of letters it should read and print
 *
 * Return: actual number of letters it could read and print
 *         0 if the file cannot be opened or read
 *         0 if filename is NULL
 *         0 if write fails or does not write the expected amount of bytes
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nread, nwritten;
	char *buffer;

	if (filename == NULL)
		return (0);

	/* Ouvre le fichier en lecture seule */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	/* Alloue la mémoire pour le buffer */
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	/* Lit le contenu du fichier */
	nread = read(fd, buffer, letters);
	if (nread == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	/* Écrit le contenu lu sur la sortie standard */
	nwritten = write(STDOUT_FILENO, buffer, nread);

	free(buffer);
	close(fd);

	/* Vérifie si l'écriture a réussi et a écrit le bon nombre d'octets */
	if (nwritten == -1 || nwritten != nread)
		return (0);

	return (nwritten);
}
