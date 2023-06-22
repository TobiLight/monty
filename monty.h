#ifndef MONTY_H
#define MONTY_H

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
#include <stddef.h>
#include <unistd.h>

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
 * @line_read: for tracking current line number
 * @tokens: used to store tokens from line
 * @instruction: a valid instruction from a line
 * @tokens_size: number of tokens created from line
 * @head: head/top of the stack (doubly linked lists of struct stack_s)
 * @stack_size: tracks the number of nodes in the stack
 * @stack: used to determine whether to use stack/queue data structure
 */
typedef struct arg_s
{
        char *line;
        FILE *stream;
        unsigned int line_read;
        int tokens_size;
        char **tokens;
        instruction_t *instruction;
        stack_t *head;
        int stack_size;
        int stack;
} arg_t;

/* Global variables and functions */
extern arg_t *arguments;

FILE *fdopen(int fd, const char *mode);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void validate_args(int);
void init_arguments();
void get_stream(char *);
void tokenizer();
void parse_instruction();
void free_node_stack(stack_t *);
void free_arguments();
void free_tokens();
void close_stream();
int is_int(char *);

void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);


#endif /* MONTY_H */
