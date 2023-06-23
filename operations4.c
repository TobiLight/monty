/*
 * File: operations4.c
 * Author: Oluwatobiloba Light
 */

#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 * 
 * Return: nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void) stack;
	(void) line_number;
	if (arguments->stack_size < 2)
		return;

	temp = arguments->head;
	while (temp)
	{
		if (temp->next == NULL)
		{
			last = temp;
			break;
		}
		temp = temp->next;
	}

	last->prev->next = NULL;
	last->next = arguments->head;
	last->prev = NULL;
	arguments->head = last;
}

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 *
 * Return: nothing
 */
void stack(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    arguments->stack = 1;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 * 
 * Return: nothing
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	arguments->stack = 0;
}
