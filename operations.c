/*
 * File: operations.c
 * Author: Oluwatobiloba Light
 */

#include "monty.h"

/**
 * push - Pushes an integer onto the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the push function is called.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (arguments->tokens_size <= 1 || !(is_int(arguments->tokens[1])))
	{
		free_arguments();
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_arguments();
		exit(EXIT_FAILURE);
	}
	(*stack)->prev = NULL;
	(*stack)->next = (*stack)->prev;
	(*stack)->n = (int)atoi(arguments->tokens[1]);
	if (arguments->head == NULL)
		arguments->head = *stack;
	else
	{
		if (arguments->stack)
		{
			(*stack)->next = arguments->head;
			arguments->head->prev = *stack;
			arguments->head = *stack;
		}
		else
		{
			temp = arguments->head;
			while (temp->next)
				temp = temp->next;
			temp->next = *stack;
			(*stack)->prev = temp;
		}
	}
	arguments->stack_size += 1;
}

/**
 * pall - Prints all the elements in the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pall function is called.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (arguments->head == NULL)
		return;

	(void)line_number;
	(void)stack;
	temp = arguments->head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * nop - does nothing
 * @stack: Pointer to the stack.
 * @line_number: Line number where the nop function is called.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pint function is called.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;

	if (arguments->head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		if (arguments->stream == NULL)
			return;

		fclose(arguments->stream);
		arguments->stream = NULL;
		free_tokens();
		free_arguments();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", arguments->head->n);
}

/**
 * pop - Removes the top element from the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pop function is called.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	if (arguments->head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		if (arguments->stream == NULL)
			return;

		fclose(arguments->stream);
		arguments->stream = NULL;
		free_tokens();
		free_arguments();
		exit(EXIT_FAILURE);
	}

	delete_stack_node();
	arguments->stack_size -= 1;
}
