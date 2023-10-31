#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <elf.h>
#include <string.h>

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

int main(int argc, char *argv[]);
void cp_file(const char *file_from, const char *file_to);
void close_file(int fd);
int open_file(const char *filename, int flags, mode_t mode);
void exit_with_error(int code, const char *format, ...);

void print_elf_header(Elf64_Ehdr *ehdr);

#endif /* MAIN_H */
