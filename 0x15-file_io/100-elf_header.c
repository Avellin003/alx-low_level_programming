#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define elf_y e_type
#define elf_z e_entry
void assess_elf(unsigned char *e_ident);
void magic(unsigned char *e_ident);
void class(unsigned char *e_ident);
void data(unsigned char *e_ident);
void version(unsigned char *e_ident);
void abi(unsigned char *e_ident);
void osabi(unsigned char *e_ident);
void type(unsigned int elf_y, unsigned char *e_ident);
void entry(unsigned long int elf_z, unsigned char *e_ident);
void elf(int elf);

/**
 * assess_elf - function
 * @e_ident: Argument
 * Return: void
 */
void assess_elf(unsigned char *e_ident)
{
	int num;

	for (num = 0; num < 4; num++)
	{
		if (e_ident[num] != 127 &&
		    e_ident[num] != 'E' &&
		    e_ident[num] != 'L' &&
		    e_ident[num] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * magic - function
 * @e_ident: Argument
 * Return: void
 */
void magic(unsigned char *e_ident)
{
	int num;

	printf("  Magic:   ");

	for (num = 0; num < EI_NIDENT; num++)
	{
		printf("%02x", e_ident[num]);

		if (num == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * class - function
 * @e_ident: Argument
 * Return: void
 */
void class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * data - function
 * @e_ident: Argument
 * Return: void
 */
void data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * version -function
 * @e_ident: Argument
 * Returns: void
 */
void version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * osabi - function
 * @e_ident: Argument
 * Return: void
 */
void osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * abi - function
 * @e_ident: Argument
 * Return: void
 */
void abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * type - function
 * @elf_y: Argument
 * @e_ident: Argument
 * Return: void
 */
void type(unsigned int elf_y, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		elf_y >>= 8;

	printf("  Type:                              ");

	switch (elf_y)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_y);
	}
}

/**
 * entry - function
 * @elf_z: Argument
 * @e_ident: Argument
 * Return: void
 */
void entry(unsigned long int elf_z, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		elf_z = ((elf_z << 8) & 0xFF00FF00) |
			  ((elf_z >> 8) & 0xFF00FF);
		elf_z = (elf_z << 16) | (elf_z >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)elf_z);

	else
		printf("%#lx\n", elf_z);
}

/**
 * elf - function
 * @elf: Argument
 * Return: void
 */
void elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Process runner
 * @argc: argument counter
 * @argv: argument vector
 * Return:0 if succes
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *h;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	h = malloc(sizeof(Elf64_Ehdr));
	if (h == NULL)
	{
		elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, h, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(h);
		elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	assess_elf(h->e_ident);
	printf("ELF Header:\n");
	magic(h->e_ident);
	class(h->e_ident);
	data(h->e_ident);
	version(h->e_ident);
	osabi(h->e_ident);
	abi(h->e_ident);
	type(h->elf_z, h->e_ident);
	entry(h->elf_y, h->e_ident);

	free(h);
	elf(o);
	return (0);
}
