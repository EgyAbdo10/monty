#include "monty.h"
/**
 * push - add elemnts to the stack
 * @stack: the doubly linked list
 * @raw_data: the number to push (as a string)
 * @line_number: teh line number we are currently in
 */
void push(stack_t **stack, char *raw_data, unsigned int line_number, FILE *file_ptr)
{
    int n = atoi(raw_data);
    stack_t *ptr;
    if (n == 0 && raw_data[0] != '0')
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        fclose(file_ptr);
        exit(EXIT_FAILURE);
    }
    ptr = malloc(sizeof(stack_t));
    if (ptr == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_dll(stack);
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
/**
 * pop - remove the top element
 * @stack: the stack address
 * @line_number: the line number of the current instruction
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *ptr = *stack;
    if (ptr == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    *stack = ptr->next;
    free(ptr);
}
/**
 * swap - swap the top two elements
 * @stack: the stack address
 * @line_number: the line number of the current instruction
 */
void swap(stack_t **stack, unsigned int line_number)
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
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        free_dll(stack);
        exit(EXIT_FAILURE);
    }
    ptr = (*stack)->next;
    (*stack)->next = ptr->next;
    (*stack)->prev = ptr;
    ptr->next = (*stack);
    ptr->prev = NULL;
    if ((*stack)->next != NULL)
    (*stack)->next->prev = (*stack);
    *stack = ptr;
}

void add(stack_t **stack, unsigned int line_number)
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
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        free_dll(stack);
        exit(EXIT_FAILURE);
    }
    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}
