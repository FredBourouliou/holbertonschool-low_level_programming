#include "main.h"

/**
 * create_file - creates a file with specific permissions
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int len = 0;
	ssize_t bytes_written;

	if (filename == NULL)
		return (-1);

	/* Ouvre/crée le fichier avec les permissions rw------- (0600) */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	/* Si text_content n'est pas NULL, écrit dans le fichier */
	if (text_content != NULL)
	{
		/* Calcule la longueur de text_content */
		while (text_content[len])
			len++;

		/* Écrit le contenu dans le fichier */
		bytes_written = write(fd, text_content, len);
		if (bytes_written == -1 || bytes_written != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
} 