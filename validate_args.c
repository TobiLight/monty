/*
 * File: validate_args.c
 * Author: Oluwatobiloba Light
*/

#include "monty.h"

/**
 * validate_args - Checks number of command line arguments
 * @argc: Number of command line arguments
 *
 * Return: Nothing
*/

void validate_args(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
