/*
 * File: tokenizer.c
 * Author: Oluwatobiloba Light
 */

#include "monty.h"

/**
 * tokenizer - Tokenizes the line read from a file
 *
 * Return: nothing
 */

void tokenizer(void)
{
	int n = 0;
	const char *delim = " $\n\t\r";
	char *line_cpy = NULL, *token = NULL;

	line_cpy = malloc(sizeof(char) * (strlen(arguments->line) + 1));
	if (line_cpy == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(line_cpy, arguments->line);
	token = strtok(line_cpy, delim);
	while (token)
	{
		arguments->tokens_size += 1;
		token = strtok(NULL, delim);
	}
	arguments->tokens = malloc(sizeof(char *) * (arguments->tokens_size + 1));
	strcpy(line_cpy, arguments->line);
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
	printf("Token sizee: %d\n", n);
	printf("Tok: %s\n", *(arguments)->tokens);

	arguments->tokens[n] = NULL;
	free(line_cpy);
}
