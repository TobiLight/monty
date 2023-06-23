/*
 * File: main.c
 * Author: Oluwatobiloba Light
 */

#include "monty.h"
arg_t *arguments = NULL;

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

	validate_args(argc);
	init_arguments();
	get_stream(argv[1]);
	while ((linelen = getline(&arguments->line, &n, arguments->stream)) != -1)
	{
		arguments->line_read += 1;
		tokenizer();
		parse_instruction();
		run_instruction();
		free_tokens();
	}

	if (arguments->stream == NULL)
		return;

	fclose(arguments->stream);
	arguments->stream = NULL;
	free_arguments();

	return (0);
}
