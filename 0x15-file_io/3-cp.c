#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * check_arg - function that checks the number of args
 * @argc: argument count
 * Return: nothing
 */
void check_arg(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * check_file_r - function that checks the readability
 * @assess: argument
 * @file:file to be checked
 * @file_from: argument
 * Return: void
 */
void check_file_r(ssize_t assess, char *file, int file_from)
{
	int file_to;

	if (assess == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		if (file_from != -1)
			close(file_from);
		if (file_to != -1)
			close(file_to);
		exit(98);
	}
}

/**
 * check_w - function
 * @assess: evaluates whether true or false
 * @file: argument
 * Return: nothing
 */
void check_w(ssize_t assess, char *file)
{
	int file_to;
	int file_from;

	if (assess == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		if (file_from != -1)
			close(file_from);
		if (file_to != -1)
			close(file_to);
		exit(99);
	}
}

/**
 * check_close - function
 * @assess: evaluates whether true or false
 * @filedescription: argument
 * Return: nothing
 */
void check_close(int assess, int filedescription)
{
	if (assess == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", filedescription);
		exit(100);
	}
}
/**
 * main - running function
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if success
 */
int main(int argc, char *argv[])
{
	int filedescription_from, filedescription_to, cl_to, cl_from;
	ssize_t lengthr, lenghtw;
	char holder[1024];
	mode_t file_p;

	check_arg(argc);
	filedescription_from = open(argv[1], O_RDONLY);
	check_file_r((ssize_t)filedescription_from, argv[1], -1, -1);
	file_p = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	filedescription_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_p);
	check_w((ssize_t)filedescription_to, argv[2], filedescription_from, -1);
	lenghtnr = 1024;
	while (lenghtr == 1024)
	{
		lenghtr = read(filedescription_from, holder, 1024);
		check_file_r(lenghtr, argv[1], filedescription_from, filedescription_to);
		lenghtw = write(filedescription_to, holder, lenghtr);
		if (lengthw != lengthr)
			lengthw = -1;
		check_w(lenghtw, argv[2], filedescription_from, filedescription_to);
	}
	cl_to = close(filedescription_to);
	cl_from = close(filedescription_from);
	check_close(close_to, filedescription_to);
	check_close(close_from, filedescription_from);
	return (0);
}
