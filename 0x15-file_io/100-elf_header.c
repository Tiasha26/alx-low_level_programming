#include "main.h"

/**
 * print_elf_header - Display information from the ELF header.
 * @ehdr: Pointer to the ELF header structure.
 */
void print_elf_header(Elf64_Ehdr *ehdr)
{
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", ehdr->e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');
	printf("Class: %s\n", ehdr->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("Data: %s\n", ehdr->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("Version: %d (current)\n", ehdr->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n", ehdr->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
			ehdr->e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
			ehdr->e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" : "<unknown>");
	printf("  ABI Version:                       %d\n", ehdr->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n", ehdr->e_type == ET_NONE ? "NONE (Unknown)" :
			ehdr->e_type == ET_REL ? "REL (Relocatable file)" :
			ehdr->e_type == ET_EXEC ? "EXEC (Executable file)" :
			ehdr->e_type == ET_DYN ? "DYN (Shared object file)" :
			ehdr->e_type == ET_CORE ? "CORE (Core file)" : "<unknown>");
	printf("  Entry point address:               0x%lx\n", (unsigned long)ehdr->e_entry);
}
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (97);
	}
	int fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		return (98);
	}
	Elf64_Ehdr ehdr;
	ssize_t bytes_read = read(fd, &ehdr, sizeof(Elf64_Ehdr));

	if (bytes_read != sizeof(Elf64_Ehdr) || ehdr.e_ident[EI_MAG0] != ELFMAG0 ||
			ehdr.e_ident[EI_MAG1] != ELFMAG1 || ehdr.e_ident[EI_MAG2] != ELFMAG2 ||
			ehdr.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file: %s\n", argv[1]);
		close(fd);
		return (98);
	}
	print_elf_header(&ehdr);
	close(fd);
	return (0);
}
