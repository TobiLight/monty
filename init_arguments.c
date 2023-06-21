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

void init_arguments()
{
	arguments = malloc(sizeof(arg_t));
	if (arguments == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	arguments->stream = NULL;
	arguments->line = NULL;
}