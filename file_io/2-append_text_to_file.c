#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int len = 0;
	ssize_t bytes_written;

	if (filename == NULL)
		return (-1);

	/* Ouvre le fichier en mode append (O_APPEND) */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	/* Si text_content n'est pas NULL, ajoute le texte à la fin du fichier */
	if (text_content != NULL)
	{
		/* Calcule la longueur de text_content */
		while (text_content[len])
			len++;

		/* Écrit le contenu à la fin du fichier */
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
