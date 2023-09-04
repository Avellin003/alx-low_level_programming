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
void asess_elf(unsigned char *e_ident);
void magix(unsigned char *e_ident);
void clss(unsigned char *e_ident);
void dta(unsigned char *e_ident);
void vers(unsigned char *e_ident);
void abis(unsigned char *e_ident);
void osabis(unsigned char *e_ident);
void tipe(unsigned int elf_y, unsigned char *e_ident);
void enter(unsigned long int elf_z, unsigned char *e_ident);
void elfs(int elf);

/**
 * asess_elf - function
 * @e_ident: Argument
 * Return: void
 */
void asess_elf(unsigned char *e_ident)
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
 * magix - function
 * @e_ident: Argument
 * Return: void
 */
void magix(unsigned char *e_ident)
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
 * clss - function
 * @e_ident: Argument
 * Return: void
 */
void clss(unsigned char *e_ident)
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
 * dta - function
 * @e_ident: Argument
 * Return: void
 */
void dta(unsigned char *e_ident)
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
 * vers -function
 * @e_ident: Argument
 * Returns: void
 */
void vers(unsigned char *e_ident)
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
 * osabis - function
 * @e_ident: Argument
 * Return: void
 */
void osabis(unsigned char *e_ident)
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
 * abis - function
 * @e_ident: Argument
 * Return: void
 */
void abis(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * tipe - function
 * @elf_y: Argument
 * @e_ident: Argument
 * Return: void
 */
void tipe(unsigned int elf_y, unsigned char *e_ident)
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
 * enter - function
 * @elf_z: Argument
 * @e_ident: Argument
 * Return: void
 */
void enter(unsigned long int elf_z, unsigned char *e_ident)
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
 * elfs - function
 * @elf: Argument
 * Return: void
 */
void elfs(int elf)
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
		elfs(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, h, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(h);
		elfs(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	asess_elf(h->e_ident);
	printf("ELF Header:\n");
	magix(h->e_ident);
	clss(h->e_ident);
	dta(h->e_ident);
	vers(h->e_ident);
	osabis(h->e_ident);
	abis(h->e_ident);
	tipe(h->elf_z, h->e_ident);
	enter(h->elf_y, h->e_ident);

	free(h);
	elfs(o);
	return (0);
}
