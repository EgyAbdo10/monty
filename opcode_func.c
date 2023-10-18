#include "monty.h"

void push(stack_t **stack, char *raw_data, unsigned int line_number)
{
    int n = atoi(raw_data);
    stack_t *ptr;
    if (n == 0 && raw_data[0] != '0')
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    ptr = malloc(sizeof(stack_t));
    if (ptr == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    ptr->n = n;
    ptr->prev = NULL;
    ptr->next = *stack;
    *stack = ptr;
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *ptr = *stack;
    (void)line_number;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->n);
        ptr = ptr->next;
    }
}
