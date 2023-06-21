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
	arguments->line = argv[1];
	arguments->stream = fopen(argv[1], O_RDONLY);

	if (arguments->stream == NULL)
	{
		close(fd);
		free(arguments);
		fprintf(stderr, "Error: Can't open file %s\n", arguments->line);
		exit(EXIT_FAILURE);
	}
	while (getline(&arguments->line, &n, arguments->stream) != -1)
	{
		printf("%s\n", arguments->line);
	}
	return (0);
}
