#include "main.h"
/**
 * exit_with_error - Print an error message and exit with a specific code.
 * @code: The exit code.
 * @format: The error message format.
 * @...: Additional arguments for the error message.
 */
void exit_with_error(int code, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	dprintf(STDERR_FILENO, format, args);
	va_end(args);
	exit(code);
}
/**
 * open_file - Open a file with error handling.
 * @filename: The name of the file to open.
 * @flags: The file open flags.
 * @mode: The file mode.
 * Return: The file descriptor on success.
 */
int open_file(const char *filename, int flags, mode_t mode)
{
	int fd = open(filename, flags, mode);

	if (fd == -1)
	{
		exit_with_error(98, "Error: Can't read from file %s\n", filename);
	}
	return (fd);
}
/**
 * close_file - Close a file with error handling.
 * @fd: The file descriptor to close.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		exit_with_error(100, "Error: Can't close fd %d\n", fd);
	}
}
/**
 * cp_file - Copy the content of one file to another.
 * @file_from: The source file name.
 * @file_to: The destination file name.
 */
void cp_file(const char *file_from, const char *file_to)
{
	int fd_from = open_file(file_from, O_RDONLY, 0);
	int fd_to = open_file(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	char buffer[1024];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(fd_from, buffer, sizeof(buffer)) > 0))
	{
		bytes_written = write(fd_to, buffer, bytes_read);

		if (bytes_written == -1)
		{
			exit_with_error(99, "Error: Can't write to file %s\n", file_to);
		}
	}
	close_file(fd_from);
	close_file(fd_to);
}
/**
 * main - Entry point for the cp program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success, other values on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		exit_with_error(97, "Usage: cp file_from file_to\n");
	}
	char *file_from = argv[1];
	char *file_to = argv[2];

	cp_file(file_from, file_to);
	return (0);
}
