#include "main.h"
/**
 * exit_with_error - Print an error message and exit with the specified code.
 * @code: The exit code.
 * @format: The format of the error message.
 * Return: void.
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
 * open_file - Open a file with specified flags and mode, and handle errors.
 * @filename: The name of the file to open.
 * @flags: The flags to use when opening the file.
 * @mode: The mode to set for the file.
 * Return: The file descriptor if successful.
 */
int open_file(const char *filename, int flags, int mode)
{
	int fd = open(filename, flags, mode);

	if (fd == -1)
	{
		exit_with_error(99, "Error: Can't open file %s\n", filename);
	}
	return (fd);
}

/**
 * close_file - Close a file descriptor and handle errors.
 * @fd: The file descriptor to close.
 * Return: void.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		exit_with_error(100, "Error: Can't close fd %d\n", fd);
	}
}

/**
 * copy_file - Copy the content from one file descriptor to another.
 * @fd_from: The source file descriptor.
 * @fd_to: The destination file descriptor.
 * Return: void.
 */
void copy_file(int fd_from, int fd_to)
{
	char buffer[1024];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(fd_from, buffer, sizeof(buffer)) > 0))
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			exit_with_error(99, "Error: Can't write to file\n");
		}
	}

	if (bytes_read == -1)
	{
		exit_with_error(98, "Error: Can't read from file\n");
	}
}

/**
 * main - The main function for copying a file.
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

	int fd_from = open_file(file_from, O_RDONLY, 0);
	int fd_to = open_file(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	copy_file(fd_from, fd_to);

	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
