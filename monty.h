#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
/*
 * File: monty.h
 * Author: Oluwatobiloba Light
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct args_s - Handle file stream
 * @stream: File that connects to the stream from file
 * @line: Strings or line of text read from the file
*/
typedef struct arg_s
{
	FILE *stream;
	char *line;
        unsigned int line_read;
        int tokens_size;
        char **tokens;
        instruction_t *instruction;
} arg_t;
/* Global variables and functions */
extern arg_t *arguments;
arg_t *arguments;

void validate_args(int);
void init_arguments();
void get_stream(char **);
void tokenizer(char *, const char *);

#endif /* MONTY_H */
