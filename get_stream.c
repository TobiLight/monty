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
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", file);
		free_arguments();
		exit(EXIT_FAILURE);
	}
	arguments->stream = fdopen(fd, "r");
	if (arguments->stream == NULL)
	{
		close(fd);
		dprintf(2, "Error: Can't open file %s\n", file);
		free_arguments();
		exit(EXIT_FAILURE);
	}
}
