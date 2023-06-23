/*
 * File: operations3.c
 * Author: Oluwatobiloba Light
 */

#include "monty.h"

/**
 * is_comment - checks the tokens if it starts with #"
 *
 * Return: 0 or 1
 */
int is_comment(void)
{
	if (
		arguments->tokens &&
		arguments->tokens[0] &&
		arguments->tokens[0][0] == '#')
		return (1);

	return (0);
}

/**
 * mul - Multiplies the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 *
 * Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void)stack;
	if (arguments->stack_size < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		if (arguments->stream == NULL)
			return;

		fclose(arguments->stream);
		arguments->stream = NULL;
		free_tokens();
		free_arguments();
		exit(EXIT_FAILURE);
	}

	temp1 = arguments->head;
	temp2 = temp1->next;

	temp2->n = temp2->n * temp1->n;
	delete_stack_node();

	arguments->stack_size -= 1;
}

/**
 * pchar - prints the char at the top of the stack,
 * followed by a new line
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)stack;
	if (arguments->head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		if (arguments->stream == NULL)
			return;

		fclose(arguments->stream);
		arguments->stream = NULL;
		free_tokens();
		free_arguments();
		exit(EXIT_FAILURE);
	}

	temp = arguments->head;

	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		if (arguments->stream == NULL)
			return;

		fclose(arguments->stream);
		arguments->stream = NULL;
		free_tokens();
		free_arguments();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", temp->n);
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 *
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)stack;
	(void)line_number;

	temp = arguments->head;

	while (temp != NULL)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");
}
