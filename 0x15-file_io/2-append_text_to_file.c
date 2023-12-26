#include "main.h"

/**
 *_strlen - a function that returns the lenght of a string
 *
 * @s: input adress
 *
 * Return: c
*/

int _strlen(char *s)
{
	int c = 0;

	if (!s)
		return (0);
	while (*s)
	{
		s++;
		c++;
	}
	return (c);
}

/**
 * append_text_to_file - a function that creates a file.
 * @filename: the name of the file
 * @text_content: the content of the file
 * Return: integer
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int file;
	ssize_t nbyt = 0, len = _strlen(text_content);

	if (!filename)
		return (-1);
	file = open(filename, O_WRONLY | O_APPEND);
	if (file == -1)
		return (-1);
	if (len)
		nbyt = write(file, text_content, len);
	close(file);
	if (nbyt == len)
		return (1);
	return (-1);
}
