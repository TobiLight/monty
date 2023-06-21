/*
 * File: main.c
 * Author: Oluwatobiloba Light
*/

#include "monty.h"

/**
 * main - Entry point monty program
 * @argc: Number of command line arguments
 * @argv: Pointer to array of strings containing
 *        the command line arguments
 *
 * Return: Always (0) Success
*/

int main(int argc, char **argv)
{
	int fd;
	size_t n = 0;

	/* Validate args */
	validate_args(argc);
	/* Initialize arguments */
	arguments = malloc(sizeof(arg_t));
	if (arguments == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);		
	}
	/* Get stream */
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free(arguments);
		exit(EXIT_FAILURE);
	}
	arguments->stream = fdopen(fd, "r");
	if (arguments->stream == NULL)
	{
		close(fd);
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	}
	while (getline(&arguments->line, &n, arguments->stream) != -1)
	{
		printf("%s\n", arguments->line);
	}
	}
	}
	return (0);
}
