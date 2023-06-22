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
	if (arguments->tokens_size <= 1 || !(is_number(arguments->tokens[1])))
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
	(*stack)->next = (*stack)->prev = NULL;
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
			stack_t *tmp = arguments->head;

			while (tmp->next)
				tmp = tmp->next;
			tmp->next = *stack;
			(*stack)->prev = tmp;
		}
	}
	arguments->stack_size += 1;
}
