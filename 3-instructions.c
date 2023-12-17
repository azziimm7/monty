#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * execute_pint - pint instruction
 * @stack: stack
 * @line_number: line number
 */

void execute_pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		state.status = EXIT_FAILURE;
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		return;
	}
	printf("%d\n", (*stack)->n);
}


/**
 * execute_pop - pop execution
 * @stack: stack
 * @line_number: line number
 */

void execute_pop(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		state.status = EXIT_FAILURE;
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		return;
	}

	if (state.mode == STACK_MODE)
		top_pop(stack);
	else
		bottom_pop(stack);
}

/**
 * execute_swp - execute swap
 * @stack: stack
 * @line_number: line number o instrctuion
 */

void execute_swp(stack_t **stack, unsigned int line_number)
{
	int *first;
	int *second;
	int temp;

	if (state.stack_size < 2)
	{
		state.status = EXIT_FAILURE;
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		return;
	}

	first = &(*stack)->n;
	second = &(*stack)->prev->n;
	temp = *first;
	*first = *second;
	*second = temp;
}
/**
 * execute_add - add execution
 * @stack: stack
 * @line_number: line numebr
 */


void execute_add(stack_t **stack, unsigned int line_number)
{
	int *first;
	int *second;

	if (state.stack_size < 2)
	{
		state.status = EXIT_FAILURE;
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		return;
	}

	first = &(*stack)->n;
	second = &(*stack)->prev->n;
	*second = (*second + *first);
	top_pop(stack);
}
/**
 * execute_nop - nop
 * @stack: pointer
 * @line_number: line number
 */
void execute_nop(stack_t **stack __attribute__((unused)),
		unsigned int line_number __attribute__((unused)))
{
	state.status = EXIT_SUCCESS;
}
