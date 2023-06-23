/*
 * File: init_arguments.c
 * Author: Oluwatobiloba Light
 */

#include "monty.h"

/**
 * init_arguments - Initializes a pointer to arg_s struct
 *
 * Return: nothing
 */

void init_arguments(void)
{
	arguments = malloc(sizeof(arg_t));
	if (arguments == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	arguments->instruction = malloc(sizeof(instruction_t));
	if (arguments->instruction == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	arguments->stream = NULL;
	arguments->line = NULL;
	arguments->line_read = 0;
	arguments->tokens_size = 0;
	arguments->stack = 1;
	arguments->stack_size = 0;
	arguments->head = NULL;
}
