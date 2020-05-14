#ifndef __MONTY__H
#define __MONTY__H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push_h(stack_t **stack, unsigned int line_number);
void pall_h(stack_t **stack, unsigned int line_number);
void swap_h(stack_t **stack, unsigned int line_number);
void nop_h(stack_t **stack, unsigned int line_number);
void pop_h(stack_t **stack, unsigned int line_number);
void pint_h(stack_t **stack, unsigned int line_number);
void get_opcode(stack_t **stack, unsigned int line_number, char *func);
void free_list(stack_t *stack);
void parse(char *buff, stack_t **stack, unsigned int line_number);
int check_digit(int chr);
void add_h(stack_t **stack, unsigned int line_number);

#endif /*__MONTY__H*/