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
    instruction_t *instruction[] = {
        {"push", push},
        {NULL, NULL}
    };

    if (arguments->tokens_size <= 0)
        return;

    // my head is paining me -_-
}