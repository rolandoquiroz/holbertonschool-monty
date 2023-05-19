#include "monty.h"

void stack_freer(stack_t *stack)
{
	stack_t *i = NULL;

	while (stack != NULL)
	{
		i = stack;
		stack = stack->next;
		free(i);
	}
}