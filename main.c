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
	ssize_t linelen;
	int i;

	validate_args(argc);
	init_arguments();
	get_stream(argv);
	while ((linelen = getline(&arguments->line, &n, arguments->stream)) != -1)
	{
		arguments->line_read += 1;
		tokenizer(arguments->line, "\n");
		printf("%s", arguments->line);
	}
	printf("\n");
	for (i = 0; i < arguments->tokens_size; i++)
		printf("%s\n", *(arguments)->tokens[i]);
	return (0);
}
