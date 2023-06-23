/*
 * File: operations2.c
 * Author: Oluwatobiloba Light
 */

#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the swap function is called.
 *
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void)stack;
	if (arguments->stack_size < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
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
	temp1->next = temp2->next;
	if (temp1->next)
		temp1->next->prev = temp1;
	temp2->next = temp1;
	temp1->prev = temp2;
	temp2->prev = NULL;
	arguments->head = temp2;
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the add function is called.
 *
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void)stack;
	if (arguments->stack_size < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
				line_number);
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

	temp2->n = temp1->n + temp2->n;
	delete_stack_node();

	arguments->stack_size -= 1;
}

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the sub function is called.
 *
 * Return: nothing
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void)stack;
	if (arguments->stack_size < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
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

	temp2->n = temp2->n - temp1->n;
	delete_stack_node();

	arguments->stack_size -= 1;
}

/**
 * _div - Divides the second top element of the stack by the top element.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the _div function is called.
 *
 * Return: nothing
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void)stack;
	if (arguments->stack_size < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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

	if (temp1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		if (arguments->stream == NULL)
			return;

		fclose(arguments->stream);
		arguments->stream = NULL;
		free_tokens();
		free_arguments();
		exit(EXIT_FAILURE);
	}

	temp2->n = temp2->n / temp1->n;
	delete_stack_node();

	arguments->stack_size -= 1;
}

/**
 * mod - Computes the rest of the division of the second top
 *       element of the stack by the top element of the stack
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 * 
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void)stack;
	if (arguments->stack_size < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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

	if (temp1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		if (arguments->stream == NULL)
			return;

		fclose(arguments->stream);
		arguments->stream = NULL;
		free_tokens();
		free_arguments();
		exit(EXIT_FAILURE);
	}

	temp2->n = temp2->n % temp1->n;
	delete_stack_node();

	arguments->stack_size -= 1;
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

	(void) stack;
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