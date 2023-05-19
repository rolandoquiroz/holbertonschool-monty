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
    
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    while((line = lines_reader(argv[1], line_number)) != NULL)
    {
        /* printf("%s\n", line); */
        
        command = strtok(line, " \r\t\n");
        if (command == NULL)
        {
            line_number++;
            free(line);
            continue;
        }

        if (strcmp(command, "push") == 0)
        {
            push(&stack, line_number);
        }
        else if (strcmp(command, "pall") == 0)
        {
            pall(&stack, line_number);
        }
        else 
        {
            dprintf(STDERR_FILENO, "L%u: usage: unknown instruction %s\n", line_number, command);
            exit(EXIT_FAILURE);
        }

        /*

        if (strcmp(command, "nop") == 0)
        {
            nop(&stack, line_number);
        }

        */
        
        free(line);
        line_number++;
    }

    stack_freer(stack);

    return (EXIT_SUCCESS);
}