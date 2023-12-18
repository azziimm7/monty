#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * execute_pstr - pstring instruction
 * @stack: stack
 * @line_number: line number
 */


void execute_pstr(stack_t **stack,
			unsigned int line_number __attribute__((unused)))
{
	stack_t *stack_top = *stack;

	while (stack_top && stack_top->n && printable_ascii(stack_top->n))
	{
		printf("%c", (char)stack_top->n);
		stack_top = stack_top->prev;
	}
	printf("\n");
}
/**
 * execute_rotl - rotl execution
 *
 * @stack: stack
 * @line_number: line number
 */

void execute_rotl(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *second;


	if (state.stack_size > 1)
	{
		second = (*stack)->prev;
		second->next = NULL;

		(*stack)->next = state.stack_bottom;
		(*stack)->prev = NULL;
		state.stack_bottom->prev = *stack;
		state.stack_bottom = *stack;

		*stack = second;
	}
}
/**
 * execute_rotr - rotr exection
 * @stack: stck
 * @line_number: line muber
 */


void execute_rotr(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *second_last;

	if (state.stack_size > 1)
	{
		second_last = state.stack_bottom->next;
		second_last->prev = NULL;

		(*stack)->next = state.stack_bottom;
		state.stack_bottom->next = NULL;
		state.stack_bottom->prev = *stack;
		*stack = state.stack_bottom;

		state.stack_bottom = second_last;
	}
}


/**
 * execute_stack - handle stack
 * @stack: stack
 * @line_number: instruction line number
 */

void execute_stack(stack_t **stack __attribute__((unused)),
		unsigned int line_number __attribute__((unused)))
{
	state.mode = STACK_MODE;
}

/**
 * execute_queue - handle execute queu
 * @stack: stack
 * @line_number: instruction line number
 */

void execute_queue(stack_t **stack __attribute__((unused)),
		unsigned int line_number __attribute__((unused)))
{
	state.mode = QUEUE_MODE;
}
