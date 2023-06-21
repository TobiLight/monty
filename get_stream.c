/*
 * File: get_stream.c
 * Author: Oluwatobiloba Light
 */

#include "monty.h"

/**
 * get_stream - Read lines from a file.
 * @line: Line read from file.
 *
 * Return: nothing
 */

void get_stream(char **line)
{
	arguments->line = line[1];
	arguments->stream = fopen(line[1], "r");
	if (arguments->stream == NULL)
	{
		fclose(arguments->line);
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
