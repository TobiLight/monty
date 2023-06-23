/*
 * File: stack.c
 * Author: Oluwatobiloba Light
*/

#include "monty.h"

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 */

void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	arguments->stack = 1;
}

/**
* delete_stack_node - delete node at the head/top
* Return: void
*/
void delete_stack_node(void)
{
	stack_t *temp;

	temp = arguments->head;
	arguments->head = temp->next;
	free(temp);
}
