/*
 * File: tokenizer.c
 * Author: Oluwatobiloba Light
 */

#include "monty.h"

/**
 * tokenizer - Tokenizes the line read from a file
 * @line: Pointer to the string to be parsed
 * @delim: Pointer to bytes that delimits tokens in the parsed string
 *
 * Return: nothing
 */

void tokenizer(char *line, const char *delim)
{
	int n = 0;
	char *line_cpy = NULL, *token = NULL;

	line_cpy = malloc(sizeof(char) * (strlen(line) + 1));
	if (line_cpy == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(line_cpy, line);
	token = strtok(line_cpy, delim);

	while (token)
	{
		arguments->tokens_size += 1;
		token = strtok(NULL, delim);
	}
	arguments->tokens = malloc(sizeof(char *) * (arguments->line_read + 1));
	strcpy(line_cpy, line);
	token = strtok(line_cpy, delim);
	while (token)
	{
		arguments->tokens[n] = malloc(sizeof(char) * (strlen(token) + 1));
		if (arguments->tokens[n] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(arguments->tokens[n], token);
		token = strtok(NULL, delim);
		n++;
	}
	arguments->tokens[n] = NULL;
	free(line_cpy);
}
