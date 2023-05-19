#include "monty.h"

void (*get_opcode(char *instruction))(stack_t **stack, unsigned int line_number)
{
	unsigned int i;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"nop", nop},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, instruction) == 0)
			return (instructions[i].f);
	}

	return (NULL);
}