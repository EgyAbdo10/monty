#include "monty.h"

/**
 * pint - prints the top
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/

void pint(stack_t **stack, unsigned int line_number)
{
        if (*stack == NULL)
        {
                fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
                free_dll(stack);
                exit(EXIT_FAILURE);
        }
        printf("%d\n", (*stack)->n);
}

void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    return;
}

void sub(stack_t **stack, unsigned int line_number)
{
    int i = 0;
    stack_t *ptr = *stack;
    while (i < 2 && ptr != NULL)
    {
        i++;
        ptr = ptr->next;
    }
    if (i != 2)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        free_dll(stack);
        exit(EXIT_FAILURE);
    }
    (*stack)->next->n -= (*stack)->n;
    pop(stack, line_number);
}
