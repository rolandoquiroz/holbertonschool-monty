#include "monty.h"

/**
 * push - Adds a new node at the beginning of a stack_t list.
 * @stack: Double pointer to the first node of the list.
 * @line_number: Data value for the new node.
 *
 * Return: NULL on failure or address of the new element on success.
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *number = NULL;
    int n;

    number = strtok(NULL, " \r\t\n");
    if (number == NULL)
    {
        dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
        free(line);
        stack_freer(*stack);
        exit(EXIT_FAILURE);
    }

    if (strcmp(number, "0") == 0)
        n = 0;
    else
    {
        n = atoi(number);
        if (n == 0)
        {
            dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
            free(line);
            stack_freer(*stack);
            exit(EXIT_FAILURE);
        }
    }

    /*printf("Numero fuera de la pila %d\n", n);*/
    
    stack_t *new_node = NULL;

	if (stack == NULL)
		return;

	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (new_node == NULL)
		return;

	new_node->n = n;
	new_node->prev = NULL;

	if (*stack == NULL)
		new_node->next = NULL;

	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;


    /*printf("Numero dentro de la pila %d\n", (*stack)->n);*/

	return;
}



void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    stack_t *i = NULL;

    if (stack == NULL)
        return;
    
    if (*stack == NULL)
        return;

    for (i = *stack; i != NULL; i = i->next)
        printf("%d\n", i->n);
}


void nop(stack_t **stack, unsigned int line_number)
{
  (void)stack, (void)line_number;
}





