/*
 * File: get_stream.c
 * Author: Oluwatobiloba Light
 */

#include "monty.h"

/**
 * get_stream - Read lines from a file.
 * @file: File to be read.
 *
 * Return: nothing
 */

void get_stream(char *file)
{
	int file_desc;

	file_desc = open(file, O_RDONLY);
	if (file_desc == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arguments->line);
		free_arguments();
		exit(EXIT_FAILURE);
	}
	arguments->stream = fdopen(file_desc, "r");
	if (arguments->stream == NULL)
	{
		close(file_desc);
		fprintf(stderr, "Error: Can't open file %s\n", arguments->line);
		free_arguments();
		exit(EXIT_FAILURE);
	}
}
