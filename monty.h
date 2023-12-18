#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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


#define STACK_MODE 0
#define QUEUE_MODE 1



typedef struct state_s
{
	stack_t *stack_bottom;
	int stack_size;
	char **args;
	int arg_count;
	int mode;
	int status;
} state_t;


extern state_t state;

/* execute */
void execute(stack_t **stack, unsigned int line_number);


/* pop */
void top_pop(stack_t **stack);
void bottom_pop(stack_t **stack);


/* execute functions */
void execute_push(stack_t **stack, unsigned int line_number);
void execute_pall(stack_t **stack, unsigned int line_number);
void execute_pint(stack_t **stack, unsigned int line_number);
void execute_pop(stack_t **stack, unsigned int line_number);
void execute_swp(stack_t **stack, unsigned int line_number);
void execute_nop(stack_t **stack, unsigned int line_number);
void execute_add(stack_t **stack, unsigned int line_number);
void execute_div(stack_t **stack, unsigned int line_number);
void execute_sub(stack_t **stack, unsigned int line_number);
void execute_mul(stack_t **stack, unsigned int line_number);
void execute_mod(stack_t **stack, unsigned int line_number);
void execute_pchr(stack_t **stack, unsigned int line_number);
void execute_pstr(stack_t **stack, unsigned int line_number);
void execute_rotl(stack_t **stack, unsigned int line_number);
void execute_rotr(stack_t **stack, unsigned int line_number);
void execute_stack(stack_t **stack, unsigned int line_number);
void execute_queue(stack_t **stack, unsigned int line_number);
void free_stck(stack_t **stack);

/* string utilities */
int word_count(char *str);
char **split_str(char *str);
char *substring(char *src, int start, int end);
void free_str_arr(char **str_arr);
bool valid_int(char *str);
void rem_coms(char *s);
bool printable_ascii(int c);

#endif

