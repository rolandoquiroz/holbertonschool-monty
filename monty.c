#include "monty.h"

char *line = NULL;

/**
 * main - Executes de commands of a monty file
 * @argc: Size of argv
 * @argv: Array of arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{

	unsigned int line_number = 1;
	char *command = NULL;
	int var;

	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	while ((line = lines_reader(argv[1], line_number)) != NULL)
	{
		
		command = strtok(line, " \r\t\n");
		if (command == NULL)
		{
			line_number++;
			free(line);
			continue;
		}
		
		if (strcmp(command, "push") == 0)
		{
			var = 1;
		}
		else if (strcmp(command, "pall") == 0)
		{
			var = 2;
		}
		else
		{
			var = 0;
		}

		switch (var)
		{
		case 1:
			push(&stack, line_number);
			break;

		case 2:
			pall(&stack, line_number);
			break;
		
		default:
			dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_number, command);
			exit(EXIT_FAILURE);
		}

		free(line);
		line_number++;
	}

	stack_freer(stack);

	return (EXIT_SUCCESS);
}