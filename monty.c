#include "monty.h"

state_t state;

/**
 * main - execute main
 * @argc: num arguments
 * @argv: array argumments
 */


int main(int argc, char **argv)
{
	FILE *input_file;
	char buffer[1024];
	int line_number = 1;
	int line_length;
	stack_t *stack_ptr = NULL; /* stack pointer */

	/* satrting */
	state.stack_bottom = stack_ptr;
	state.stack_size = 0;
	state.mode = STACK_MODE;
	state.status = EXIT_SUCCESS;

	/* if no suply */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	/* openning */
	input_file = fopen(argv[1], "r");

	/* does nt exist */
	if (input_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (fgets(buffer, sizeof(buffer), input_file))
	{
		line_length = strlen(buffer);

		if (line_length == 0)
			continue;
		if (buffer[line_length - 1] == '\n')
		{
			buffer[line_length - 1] = '\0';
			line_length--;
		}
		rem_coms(buffer);
		state.args = split_str(buffer);
		state.arg_count = word_count(buffer);

		if (state.arg_count > 0)
			execute(&stack_ptr, line_number);

		if (state.status == EXIT_FAILURE)
			return (EXIT_FAILURE);
		line_number++;

		free_str_arr(state.args);
	}
	free_stck(&stack_ptr);
	fclose(input_file);

	return (0);
}
