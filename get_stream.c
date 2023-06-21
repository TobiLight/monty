/*
 * File: get_stream.c
 * Author: Oluwatobiloba Light
 */

#include <unistd.h>
#include "monty.h"

/**
 * get_stream - Read lines from a file.
 * @line: Line read from file.
 *
 * Return: nothing
 */

void get_stream(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arguments->line);
		if (arguments == NULL)
			return;
		if (arguments->line)
		{
			free(arguments->line);
			arguments->line = NULL;
		}
		free(arguments);
		exit(EXIT_FAILURE);
	}
	arguments->stream = fdopen(fd, "r");
	if (arguments->stream == NULL)
	{
		close(fd);
		fprintf(stderr, "Error: Can't open file %s\n", arguments->line);
		if (arguments == NULL)
			return;
		if (arguments->line)
		{
			free(arguments->line);
			arguments->line = NULL;
		}
		free(arguments);
		exit(EXIT_FAILURE);
	}
}
