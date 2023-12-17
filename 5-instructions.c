#include <stdio.h>
#include <stdlib.h>
#include "monty.h"


/**
 * free - removes all items
 * @stack: stack
 */

void free(stack_t **stack)
{
	while (state.stack_size > 0)
		top_pop(stack);
}
