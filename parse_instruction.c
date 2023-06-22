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
	int i;
	instruction_t *instruction[] = {
		{"push", &push},
		{"pall", &pall},
		{NULL, NULL}
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
	if (arguments->stream == NULL)
		return;

	fclose(arguments->stream);
	arguments->stream = NULL;
	free_tokens(); /* free tokens */
	free_arguments();
}
