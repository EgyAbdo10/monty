#include "monty.h"
/**
 * get_opcode_func - get the proper opcode function
 * @opcode: the opcode from tyhe monty file
 * @line_num: the line number
 * Return: the proper function or NULL if failed
 */
void (*get_opcode_func(char *opcode, unsigned int line_num))(stack_t**, unsigned int)
{
    int i = 0;
    instruction_t opcodes[] = {
    {"pall", pall}/*,
    {"pint", pint},
    {"swap", swap},
    {"add", add},
    {"nod", nod},
    */
};
    while (i < 5)
    {
        if (strcmp(opcode, (opcodes + i)->opcode) == 0)
        {
            return (opcodes[i].f);
        }
        i++;
    }
    if (i == 5)
    {
    fprintf(stderr, "L%d: unknown instruction %s", line_num, opcode);
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
    opcode = strtok(line, "$ \t");
    if (strcmp(opcode, "push") == 0)
    push(&stack, strtok(NULL, "$ \t"), line_num);
    else
    {
    f_ptr = get_opcode_func(opcode, line_num);
    f_ptr(&stack, line_num);
    }
    }
    return (0);
}
