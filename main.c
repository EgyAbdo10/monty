#include "monty.h"

/**
 * free_dll - free a doubly linked list
 * @stack: the stack to free
 */
void free_dll(stack_t **stack)
{
    stack_t *temp;
    while ((*stack) != NULL)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}

/**
 * is_line_empty - check if the line is empty
 * @line: the line
 * Return: 1 if empty or 0 if not
 */
int is_line_empty(char *line)
{
    size_t i = 0;
    if (line[0] == '$')
    return (1);
    for (; i < strlen(line) - 2; i++)
    {
        if (line[i] != ' ' && line[i] != '\t')
        return (0);
    }
    return (1);
}

/**
 * get_opcode_func - get the proper opcode function
 * @opcode: the opcode from tyhe monty file
 * @line_num: the line number
 * Return: the proper function or NULL if failed
 */
void (*get_opcode_func(char *opcode, unsigned int line_num, FILE *file_ptr, stack_t **stack))(stack_t**, unsigned int)
{
    int i = 0;
    instruction_t opcodes[] = {
    {"pall", pall},
    {"pint", pint},
    {"pop", pop},
    {"swap", swap},
    {"add", add},
    {"nop", nop},
    {"sub", sub},
    {"div", my_div},
    {"mul", mul},
    {"mod", mod}
};
    while (i < 10)/*increment this number when ading a new opcode func*/
    {
        if (strcmp(opcode, (opcodes + i)->opcode) == 0)
        {
            return (opcodes[i].f);
        }
        i++;
    }
    if (i == 10)/*increment this number when ading a new opcode func*/
    {
    fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
    free_dll(stack);
    fclose(file_ptr);
    exit(EXIT_FAILURE);
    }
    return (NULL);
}


/**
 * main - implement instructions in the monty file
 * @argc: the the number of arguments
 * @argv: the argument vector
 * Return: (0) on success
*/
int main(int argc, char *argv[])
{
    unsigned int line_num = 0;
    char buffer[1024];
    char *line, *opcode;
    FILE *file_ptr;
    stack_t *stack = NULL;
    void (*f_ptr)(stack_t **stack,  unsigned int line_number);
    if (argc != 2)
    {
    fprintf(stderr, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
    }
    file_ptr = fopen(argv[1], "r");
    if (file_ptr == NULL)
    {
    fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
    }
    while (fgets(buffer, sizeof(buffer), file_ptr) != NULL)
    {
    line_num++;
    line = buffer;
    if (is_line_empty(line) == 0)
    {
    opcode = strtok(line, "$ \t\n");
    if (strcmp(opcode, "push") == 0)
    push(&stack, strtok(NULL, "$ \t\n"), line_num, file_ptr);
    else
    {
    f_ptr = get_opcode_func(opcode, line_num, file_ptr, &stack);
    f_ptr(&stack, line_num);
    }
    }
    }
    fclose(file_ptr);
    free_dll(&stack);
    return (0);
}
