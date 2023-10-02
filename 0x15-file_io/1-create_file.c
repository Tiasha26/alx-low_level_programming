#include "main.h"

/**
 * create_file - creates a file and writes text content to it.
 * @filename: the name of the file to create.
 * @text_content: the NULL-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, written_bytes = 0;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[written_bytes])
			written_bytes++;
		if (write(fd, text_content, written_bytes) == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
