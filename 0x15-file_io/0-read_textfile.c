#include "main.h"

/**
 * read_textfile - reads a text file and prints it to standard output.
 * @filename: the name of the file to read.
 * @letters: the number of letters it should read and print.
 *
 * Return: the actual number of letters it could read and print.
 * if the file can't be opened or read, return 0.
 * if filename is NULL, return 0.
 * if write fails or does not write the expected amount of bytes, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t n_read, n_written;
	char *buffer = malloc(sizeof(char) * letters);
	int fd = open(filename, O_RDONLY);

	if (filename == NULL)
		return (0);
	if (fd == -1)
		return (0);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}
	n_read = read(fd, buffer, letters);

	if (n_read == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}
	n_written = write(STDOUT_FILENO, buffer, n_read);

	if (n_written == -1 || n_written != n_read)
	{
		free(buffer);
		close(fd);
		return (0);
	}
	free(buffer);
	close(fd);
	return (n_written);
}
