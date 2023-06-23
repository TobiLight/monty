/*
 * File: operations4.c
 * Author: Oluwatobiloba Light
 */

#include "monty.h"

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
