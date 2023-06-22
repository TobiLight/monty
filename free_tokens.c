/*
 * File: free_tokens.c
 * Author: Oluwatobiloba Light
 */

#include "monty.h"

/**
 * free_tokens - Frees the allocated memory for tokens.
 */
void free_tokens(void)
{
	int i;

	if (arguments->tokens == NULL)
		return;

	for (i = 0; arguments->tokens[i] != NULL; i++)
	{
		free(arguments->tokens[i]);
	}
	free(arguments->tokens);
	arguments->tokens = NULL;
}
