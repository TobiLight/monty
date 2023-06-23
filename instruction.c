/*
 * File: parse_instruction.c
 * Author: Oluwatobiloba Light
 */

#include "monty.h"

/**
 * parse_instruction - Sets and executes the instruction based on
 *                     the tokens
 *
 * Return: nothing
 */
void parse_instruction(void)
{
	int i = 0;
	instruction_t instruction[] = {
		{"push", &push}, {"pall", &pall},
		{"nop", &nop}, {"pint", &pint},
		{"pop", &pop}, {"swap", &swap},
		{"add", &add}, {"sub", &sub},
		{"div", &_div}, {"mod", &mod},
		{"mul", &mul}, {"pchar", &pchar},
		{"pstr", &pstr}, {"rotl", &rotl},
		{"rotr", &rotr}, {"stack", &_stack},
		{"queue", &queue}, {NULL, NULL}
	};


	if (arguments->tokens_size <= 0)
		return;
	if (arguments->tokens[0][0] == '#')
	{
		arguments->instruction->opcode = "nop";
		arguments->instruction->f = nop;
		return;
	}
	for (i = 0; instruction[i].opcode != NULL; i++)
	{
		if (strcmp(instruction[i].opcode, arguments->tokens[0]) == 0)
		{
			arguments->instruction->opcode = instruction[i].opcode;
			arguments->instruction->f = instruction[i].f;
			return;
		}
	}
	/* close stream */
	close_stream();
	free_tokens(); /* free tokens */
	free_arguments();
}

/**
 * run_instruction - Runs the instruction specified by the arguments.
 */
void run_instruction(void)
{
	stack_t *stack = NULL;

	if (arguments->tokens_size == 0)
		return;
	arguments->instruction->f(&stack, arguments->line_read);
}
