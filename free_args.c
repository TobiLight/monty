/*
 * File: free_args.c
 * Author: Oluwatobiloba Light
 */

#include "monty.h"

/**
 * close_stream - Closes the file stream and sets it to NULL.
 */
void close_stream(void)
{
	if (arguments->stream == NULL)
		return;

	fclose(arguments->stream);
	arguments->stream = NULL;
}

/**
 * free_node_stack - Free the nodes in a stack
 * @head: first node of a stack_t list
 * Return: void
 */
void free_node_stack(stack_t *head)
{
	stack_t *temp = head;

	while (temp)
	{
		temp = temp->next;
		free(head);
		head = temp;
		arguments->stack_size -= 1;
	}
}

/**
 * free_tokens - Frees the allocated memory for tokens.
 */
void free_tokens(void)
{
	int i;

	if (arguments->tokens == NULL)
		return;

	i = 0;
	while (arguments->tokens[i])
	{
		free(arguments->tokens[i]);
		arguments->tokens_size -= 1;
		i++;
	}
	free(arguments->tokens);
	arguments->tokens = NULL;
}

/**
 * free_arguments - free memory allocated to arguments pointer
 */
void free_arguments(void)
{
	if (arguments == NULL)
		return;
	if (arguments->instruction)
	{
		free(arguments->instruction);
		arguments->instruction = NULL;
	}
	if (arguments->head)
		free_node_stack(arguments->head);
	arguments->head = NULL;
	
	if (arguments->line)
	{
		free(arguments->line);
		arguments->line = NULL;
	}
	arguments->line_read = 0;
	arguments->stack_size = 0;
	free(arguments);
}
