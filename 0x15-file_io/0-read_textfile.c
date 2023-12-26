#include "main.h"

/**
 * read_textfile - read a text file and prints it to the standard output.
 * @filename: name of the file
 * @letters: number of letter to read
 * Return: nletters
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;
	ssize_t nletters;
	char array[BUF * 8];

	if (!filename || !letters)
		return (0);

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);
	nletters = read(file, array, letters);
	nletters = write(STDOUT_FILENO, array, nletters);
	close(file);
	return (nletters);
}
