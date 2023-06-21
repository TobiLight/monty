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

	validate_args(argc);
	init_arguments();
	get_stream(argv);
	while ((linelen = getline(&arguments->line, &n, arguments->stream)) != -1)
	{
		arguments->line_read += 1;
		// tokenize line -- get words only
		// get instructios -- get the opcode from the tokens array.. this is after tokenization
		// run instruction - run the function associated with the opcode
		// uhmm idk what to do here yet 😕
		printf("%s", arguments->line);
	}
	printf("\n");
	printf("Number of lines read: %d\n", arguments->line_read);
	return (0);
}
