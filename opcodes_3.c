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

void pchar(stack_t **stack, unsigned int line_number)
{
    if ((*stack) == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    if ((*stack)->n > 127 || (*stack)->n < 0)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%c\n", (*stack)->n);
}

void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *ptr;
    stack_t *last;
    (void)line_number;
    if ((*stack) == NULL)
    return;
    ptr = (*stack)->next;
    last = (*stack);
    while (last->next != NULL)
    {
        last = last->next;
    }
    if ((*stack)->next != NULL)
    {
    (*stack)->prev = last;
    (*stack)->next = NULL;
    last->next = *stack;
    ptr->prev = NULL;
    (*stack) = ptr;
    }
}
