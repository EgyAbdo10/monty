#include "monty.h"

void mod(stack_t **stack, unsigned int line_number)
{
    int i = 0, first_num, second_num, res;
    stack_t *ptr = *stack;
    while (i < 2 && ptr != NULL)
    {
        i++;
        ptr = ptr->next;
    }
    if (i != 2)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        free_dll(stack);
        exit(EXIT_FAILURE);
    }
    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }
    first_num = (*stack)->next->n;
    second_num = (*stack)->n;
    res = first_num / second_num;
    (*stack)->next->n = first_num - (second_num * res);
    pop(stack, line_number);
}
