#include "main.h"
/**
 * print_elf_header - Print information from the ELF header.
 * @header: Pointer to the ELF header.
 */
void print_elf_header(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");
	const char *elf_class = (header->e_ident[EI_CLASS] == ELFCLASS32) ?
		"ELF32" : "ELF64";

	printf("  Class:            %s\n", elf_class);
	const char *elf_data = (header->e_ident[EI_DATA] == ELFDATA2LSB) ?
		"2's complement, little endian" : "2's complement, big endian";

	printf("  Data:                %s\n", elf_data);
	printf("  Version:  %d (current)\n", (int)header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		default:
			printf("<unknown: %d>\n", (int)header->e_ident[EI_OSABI]);
			break;
	}
	printf("  ABI Version:     %d\n", (int)header->e_ident[EI_ABIVERSION]);
	const char *elf_type = (header->e_type == ET_EXEC) ?
		"EXEC (Executable file)" : "DYN (Shared object file)";

	printf("  Type:                        %s\n", elf_type);
	printf("  Entry point address:             0x%lx\n", (long)header->e_entry);
}
/**
 * main - Entry point for displaying ELF header information.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success, other values on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}
	int fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		return (98);
	}
	Elf64_Ehdr elf_header;

	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr) ||
			memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file: %s\n", argv[1]);
		close(fd);
		return (98);
	}
	print_elf_header(&elf_header);
	close(fd);
	return (0);
}
