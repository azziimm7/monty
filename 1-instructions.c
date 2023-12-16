#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * execute - execute instruction
 * @stack: stack
 * @line_number: line number of the instruction
 */


void execute(stack_t **stack, unsigned int line_number)
{
	intruction_t instructions[] = {
		{"push", &exec_push},
		{"pop", &exec_pop},
		{"swap", &exec_swap},
		{"add", &exec_add},
		{"nop", &exec_nop},
		{"pall", &exec_pall},
		{"pint", &exec_pint},
		{"pchar", &exec_pchar},
		{"pstr", &exec_pstr},
		{"rotl", &exec_rotl},
		{"rotr", &exec_rotr},
		{"stack", &exec_stack},
		{"queue", &exec_queue};
		{"sub", &exec_sub},
		{"div", &exec_div},
		{"mul", &exec_mul},
		{"mod", &exec_mod}
	};
	unsigned long int i;
	unsigned long count = sizeof(instructions)
		/ sizeof(instruction_t);
	for (i = 0; i < count; i++)
	{
		if (!strcmp(state.args[0], instructions[i].opcode))
		{
			instructions[i].f(Stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: UNknown instruction %s\n", line_number, state.args[0]);
	state.status = EXIT_FAILURE;
}

/**
 * top_pop - popo first element
 * @stack: stack
 */


void top_pop(stack_t **stack)
{
	satck_T current = *stack;
	*stack = (*stack)->prev;

	if (*stack)
		(*stack)->next = NULL;
	else
		state.stack_bottom = NULL;

	state.stack_size--;
	free(current);
}
/**
 * bottom_pop - pop bottom of the stack
 * @stack: stack
 */

void bottom_pop(stack_t **stack)
{
	stack_t *current = state.stack_bottom;

	state.stack_bottom = state.stack_bottom->next;

	if (state.stack_bottom)
		state.stack_bottom->prev = NULL;
	else
		*stack = NULL;
	state.stack_size--;
	return (current);
}

/**
 * exec_push - ecectue push
 * @stack: pointer
 * @line_number: line number of instruction
 */

void exec_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack_entry = malloc(sizeof(stack_t));
	int operand;

	if (!new_stack_entry)
	{
		state.status = EXIT_FAILURE;
		fprintf(stderr, "Error: malloc failed\n");
		return;
	}

	if (state.arg_count < 2 || !is_valid_integer(state.args[1]))
	{
		state.status = EXIT_FAILURE;
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		return;
	}
	else
	{
		operand = atoi(state.args[1]);
	}

	new_stack_entry->n = operand;
	new_stack_entry->next = NULL;
	new_stack_entry->prev = *stack;

	if (*stack)
	{
		if (state.mode == STACK_MODE)
		{
			(*stack)->next = new_stack_entry;
			*stack = (*stack)->next;
		}
		else
		{
			new_stack_entry->next = state.stack_bottom;
			new_stack_entry->prev = NULL;
			state.stack_bottom->prev = new_stack_entry;
			state.stack_bottom = new_stack_entry;
		}
	}
	else
	{
		*stack = new_stack_entry;
		state.stack_bottom = *stack;
	}
	state.stack_size++;
}
/**
 * exec_pall - excute pall
 * @stack: stack
 * @line_number: line number of instruction
 */

void exec_pall(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
