#include "main.h"
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_class - Prints the class from an ELF header.
 *
 * @header: Header information
 *
 * Return: void
 */
void print_class(char *header)
{
	printf("  %-35s", "Class:");
	if (header[4] == 2)
		printf("ELF64\n");
	else if (header[4] == 1)
		printf("ELF32\n");
	else
		printf("<unknown: %02hx>", header[4]);
}

/**
 * print_data - Prints the information about data organization
 * from the ELF header.
 *
 * @header: Header information
 *
 * Return: void
 */
void print_data(char *header)
{
	printf("  %-35s", "Data:");
	if (header[5] == 1)
		printf("2's complement, little endian\n");
	else if (header[5] == 2)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %02hx>", header[5]);
}

/**
 * print_version - Prints version info from the ELF header.
 *
 * @header: Header information
 *
 * Return: void
 */
void print_version(char *header)
{
	printf("  %-35s", "Version:");
	if (header[6] <= EV_CURRENT)
	{
		printf("%d", header[6]);
		if (header[6] == EV_CURRENT)
			printf(" (current)\n");
		else
			printf("\n");
	}
	else
	{
		printf("49 <unknown %%lx>");
	}
}

/**
 * print_abi - Prints ABI version from header information.
 *
 * @header: Header information
 *
 * Return: void
 */
void print_abi(char *header)
{
	printf("  %-35s", "OS/ABI:");
	switch (header[7])
	{
	case 0:
		printf("UNIX - System V\n");
		break;
	case 1:
		printf("UNIX - HP-UX\n");
		break;
	case 2:
		printf("UNIX - NetBSD\n");
		break;
	case 3:
		printf("UNIX - Linux\n");
		break;
	case 4:
		printf("UNIX - GNU Hurd\n");
		break;
	case 6:
		printf("UNIX - Solaris\n");
		break;
	case 7:
		printf("UNIX - AIX\n");
		break;
	case 8:
		printf("UNIX - IRIX\n");
		break;
	case 9:
		printf("UNIX - FreeBSD\n");
		break;
	case 10:
		printf("UNIX - Tru64\n");
		break;
	case 11:
		printf("UNIX - Novell Modesto\n");
		break;
	case 12:
		printf("UNIX - OpenBSD\n");
		break;
	case 13:
		printf("UNIX - Open VMS\n");
		break;
	case 14:
		printf("UNIX - NonStop Kernel\n");
		break;
	case 15:
		printf("UNIX - AROS\n");
		break;
	case 16:
		printf("UNIX - Fenix OS\n");
		break;
	case 17:
		printf("UNIX - CloudABI\n");
		break;
	default:
		printf("<unknown: %02x>\n", header[7]);
	}
	printf("  %-35s%d\n", "ABI Version:", header[8]);
}

/**
 * print_type - Prints ELF file type from header info.
 *
 * @header: Header information
 *
 * Return: void
 */
void print_type(char *header)
{
	int index;

	if (header[5] == 1)
		index = 16;
	else
		index = 17;
	printf("  %-35s", "Type:");
	if (header[index] == 1)
		printf("REL (Relocatable file)\n");
	else if (header[index] == 2)
		printf("EXEC (Executable file)\n");
	else if (header[index] == 3)
		printf("DYN (Shared object file)\n");
	else if (header[index] == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown>: %02x%02x\n", header[16], header[17]);
}

/**
 * print_entry - Prints entry address of executable from header.
 *
 * @header: Header information
 *
 * Return: void
 */
void print_entry(char *header)
{
	int i, end;

	printf("  %-35s0x", "Entry point address:");
	if (header[4] == 2)
		end = 0x1f;
	else
		end = 0x1b;
	if (header[5] == 1)
	{
		i = end;
		while (header[i] == 0 && i > 0x18)
			i--;
		printf("%x", header[i--]);
		while (i >= 0x18)
			printf("%02x", (unsigned char)header[i--]);
		printf("\n");
	}
	else
	{
		i = 0x18;
		while (header[i] == 0)
			i++;
		printf("%x", header[i++]);
		while (i <= end)
			printf("%02x", (unsigned char)header[i++]);
		printf("\n");
	}
}

/**
 * main - Parses an ELF header file.
 *
 * @ac: Number of args
 * @av: Argument strings
 *
 * Return: 0 on success
 * 1 on incorrect arg number
 * 2 on file open failure
 * 3 on read failure
 * 4 on failure to read enough bytes for a 32-bit file
 * 98 if ELF magic is not matched
 */
int main(int ac, char *av[])
{
	int ifile, i;
	char header[32];

	if (ac != 2)
		return (1);
	ifile = open(av[1], O_RDONLY);
	if (ifile == -1)
		return (2);
	i = read(ifile, header, 32);
	if (i == -1)
		return (3);
	if (i < 28)
		return (4);
	if (header[0] != 0x7f || header[1] != 'E' || header[2] != 'L' || header[3] != 'F')
	{
		dprintf(STDERR_FILENO,
			"readelf: Error: hellofile: Failed to read file header\n");
		return (98);
	}
	printf("ELF Header:\n  Magic:   ");
	for (i = 0; i < 16; i++)
		printf("%02x ", (unsigned int)header[i]);
	printf("\n");
	print_class(header);
	print_data(header);
	print_version(header);
	print_abi(header);
	print_type(header);
	print_entry(header);
	/*return value*/
	return (0);
}
