#include "monty.h"
/**
 * push - add elemnts to the stack
 * @stack: the doubly linked list
 * @raw_data: the number to push (as a string)
 * @line_number: teh line number we are currently in
 */
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
/**
 * pall - print all stack elements
 * @stack: the address of the stack
 * @line_number: teh line number we are currently in
 */
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