#include "main.h"
#include <unistd.h>
#include <fcntl.h>

/**
 * create_file - Creates a file with read/write permissions
 * @filename: name of the file
 * @text_content: the text to write into the file
 * close (fd)
 * Repetition of my File I/O project
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	/*Variable Declaration*/
	int wr, fd;
	int len;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
	{
		fd = open(filename, O_WRONLY | O_CREAT, 0600);
		if (fd == -1)
			return (-1);
		return (1);
	}
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	for (len = 0; text_content[len]; len++)
	{}
	wr = write(fd, text_content, len);
	if (wr == -1)
	{
		close(fd);
		return (-1);
	}
	/*close fd*/
	close(fd);
	/*Return Value*/
	return (1);
}

