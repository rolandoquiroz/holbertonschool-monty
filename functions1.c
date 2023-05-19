#include "monty.h"

void pint(stack_t **stack, unsigned int line_number)
{
    (void)stack, (void)line_number;
}


int contains_letter(const char *str)
{
	size_t i;

	if (*str == '-')
		str++;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
	}

	return (0);
}
