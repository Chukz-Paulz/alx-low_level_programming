#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - reads and prints text from a file
 * @filename: name of the file
 * @letters: number of characters to read
 *
 * Return: the actual number of letters read, 0 if end of file or error
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	/*Declaration*/
	int wrotechars, file, length;
	char *buf;

	if (filename == NULL || letters == 0)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		free(buf);
		return (0);
	}

	length = read(file, buf, letters);
	if (length == -1)
	{
		free(buf);
		close(file);
		return (0);
	}

	wrotechars = write(STDOUT_FILENO, buf, length);

	free(buf);
	close(file);
	if (wrotechars != length)
		return (0);
	/*return value length of text*/
	return (length);
}
