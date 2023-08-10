#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * check_num - evaluates the num of args
 * @argc: argument count
 * Return: nothing
 */
void check_num(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * check_exist - evaluates whether the function exist
 * @assess: views either true or false
 * @file: argument
 * @fd_from: argument
 * @fd_to: argument
 * Return: nothing
 */
void check_exist(ssize_t assess, char *file, int fd_from, int fd_to)
{
	if (assess == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		if (fd_from != -1)
			close(fd_from);
		if (fd_to != -1)
			close(fd_to);
		exit(98);
	}
}

/**
 * check_file - function
 * @assess: evaluates whether true or false
 * @file: argument
 * @fd_from: argument
 * @fd_to: argument
 * Return: nothing
 */
void check_file(ssize_t assess, char *file, int fd_from, int fd_to)
{
	if (assess == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		if (fd_from != -1)
			close(fd_from);
		if (fd_to != -1)
			close(fd_to);
		exit(99);
	}
}

/**
 * check_close - function
 * @assess: evaluates whether true or false
 * @fd: argument
 * Return: nothing
 */
void check_close(int assess, int fd)
{
	if (assess == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
/**
 * main -running function
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, close_to, close_from;
	ssize_t lenr, lenw;
	char holder[1024];
	mode_t file_perm;

	check_num(argc);
	fd_from = open(argv[1], O_RDONLY);
	check_exist((ssize_t)fd_from, argv[1], -1, -1);
	file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
	check_file((ssize_t)fd_to, argv[2], fd_from, -1);
	lenr = 1024;
	while (lenr == 1024)
	{
		lenr = read(fd_from, holder, 1024);
		check_exist(lenr, argv[1], fd_from, fd_to);
		lenw = write(fd_to, holder, lenr);
		if (lenw != lenr)
			lenw = -1;
		check_file(lenw, argv[2], fd_from, fd_to);
	}
	close_to = close(fd_to);
	close_from = close(fd_from);
	check_close(close_to, fd_to);
	check_close(close_from, fd_from);
	return (0);
}
