#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * execute_sub - sub instruction
 * @stack: stack
 * @line_number: line number of inst
 */

void execute_sub(stack_t **stack, unsigned int line_number)
{
	int *first;
	int *second;

	if (state.stack_size < 2)
	{
		state.status = EXIT_FAILURE;
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		return;
	}
	first = &(*stack)->n;
	second = &(*stack)->prev->n;
	*second = (*second - *first);
	top_pop(stack);
}
/**
 * execute_div - execute division
 * @stack: stack
 * @line_number: instruction line number
 */


void execute_div(stack_t **stack, unsigned int line_number)
{
	int *first;
	int *second;

	if (state.stack_size < 2)
	{
		state.status = EXIT_FAILURE;
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		return;
	}

	first = &(*stack)->n;
	second = &(*stack)->prev->n;

	if (*first == 0)
	{
		state.status = EXIT_FAILURE;
		fprintf(stderr, "L%d: division by zero\n", line_number);
		return;
	}
	*second = (*second / *first);
	top_pop(stack);
}
/**
 * execute_mul - execute multiblication
 * @stack: stack
 * @line_number: lien number
 */

void execute_mul(stack_t **stack, unsigned int line_number)
{
	int *first;
	int *second;

	if (state.stack_size < 2)
	{
		state.status = EXIT_FAILURE;
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		return;
	}
	first = &(*stack)->n;
	second = &(*stack)->prev->n;
	*second = (*second * *first);
	top_pop(stack);
}
/**
 * execute_mod - modiication
 * @stack: stack pointer
 * @line_number: line number
 */

void execute_mod(stack_t **stack, unsigned int line_number)
{
	int *first;
	int *second;

	if (state.stack_size < 2)
	{
		state.status = EXIT_FAILURE;
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		return;
	}

	first = &(*stack)->n;
	second = &(*stack)->prev->n;

	if (*first == 0)
	{
		state.status = EXIT_FAILURE;
		fprintf(stderr, "L%d: division by zero\n", line_number);
		return;
	}
	*second = (*second % *first);

	top_pop(stack);
}

/**
 * execute_pchr - execute pchar
 * @stack: stack
 * @line_number: line_number
 */

void execute_pchr(stack_t **stack, unsigned int line_number)
{
	int first;

	if (!(*stack))
	{
		state.status = EXIT_FAILURE;
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		return;
	}

	first = (*stack)->n;

	if (!printable_ascii(first))
	{
		state.status = EXIT_FAILURE;
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		return;
	}

	printf("%c\n", (char)first);
}
