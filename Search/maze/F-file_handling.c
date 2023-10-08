#include "main.h"

/**
 * handle_file - handles file arguments in CLI;
 * @filename: file argument passed;
 * Return: returns xstat;
 */

char **handle_file(char *filename)
{
	char c, *file_lines = NULL, **arr = NULL;
	int i = 0, fd = 0, bytes = 0;

	if (filename == NULL)
		return (NULL);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (NULL);
	}

	file_lines = malloc(sizeof(char) * 100000);
	while (1)
	{
		bytes = read(fd, &c, sizeof(char));
		if (bytes == -1 || bytes == 0)
			break;
		file_lines[i] = c;
		i++;
	}
	file_lines[i] = '\0';
	close(fd);

	arr = split_str(file_lines, "\n");
	free(file_lines);

	return (arr);
}
