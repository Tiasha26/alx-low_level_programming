#include "main.h"
int open_file(const char *filename, int flags, int mode);
int copy_file(int from_fd, int to_fd);
/**
 * main - Copies the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or the corresponding error code on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}
	fd_from = open_file(argv[1], O_RDONLY, 0);
	fd_to = open_file(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (copy_file(fd_from, fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(fd_from);
		close(fd_to);
		exit(99);
	}
	close(fd_from);
	close(fd_to);
	return (0);
}

/**
 * open_file - Opens a file with specified flags and mode.
 * @filename: The name of the file.
 * @flags: File opening flags.
 * @mode: File permissions mode.
 *
 * Return: File descriptor on success, or exits with an error
 * message on failure.
 */
int open_file(const char *filename, int flags, int mode)
{
	int fd = open(filename, flags, mode);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (fd);
}

/**
 * copy_file - Copies data from one file descriptor to another.
 * @from_fd: Source file descriptor.
 * @to_fd: Destination file descriptor.
 *
 * Return: 0 on success, -1 on failure.
 */
int copy_file(int from_fd, int to_fd)
{
	char buffer[1024];
	ssize_t read_bytes, write_bytes;

	while ((read_bytes = read(from_fd, buffer, 1024)) > 0)
	{
		write_bytes = write(to_fd, buffer, read_bytes);

		if (write_bytes == -1 || write_bytes != read_bytes)
			return (-1);
	}
	return ((read_bytes == -1) ? -1 : 0);
}
