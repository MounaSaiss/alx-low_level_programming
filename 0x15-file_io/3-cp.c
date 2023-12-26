#include "main.h"
#define USAGE "Usage: cp file_from file_to\n"
#define NOT_READ "Error: Can't read from file %s\n"
#define NOT_WRITE "Error: Can't write to %s\n"
#define NOT_CLOSE "Error: Can't close fd FD_VALUE%d\n"
#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)
/**
 * main - Entry point (program)
 * @ac: the number of arguments
 * @av: the arguments
 * Return: 1 or 0
 */
int main(int ac, char **av)
{
	int from_file = 0, to_file = 0;
	ssize_t b;
	char array[BUF];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, USAGE);
		exit(97);
	}
	from_file = open(av[1], O_RDONLY);
	if (from_file == -1)
		dprintf(STDERR_FILENO, NOT_READ, av[1]), exit(98);
	to_file = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
	if (to_file == -1)
		dprintf(STDERR_FILENO, NOT_WRITE, av[2]), exit(99);
	while ((b = read(from_file, array, BUF)) > 0)
		if (write(to_file, array, b) != b)
			dprintf(STDERR_FILENO, NOT_WRITE, av[2]), exit(99);
	if (b == -1)
		dprintf(STDERR_FILENO, NOT_READ, av[1]), exit(98);
	from_file = close(from_file);
	to_file = close(to_file);
	if (from_file)
		dprintf(STDERR_FILENO, NOT_CLOSE, from_file), exit(100);
	if (to_file)
		dprintf(STDERR_FILENO, NOT_CLOSE, to_file), exit(100);
	return (EXIT_SUCCESS);
}

