# ALX monty project
A group project carried out by Maher and Charis.  
The goal of this project is to create an interpreter for Monty ByteCodes files.
# General Requirements
1. Allowed editors: vi, vim, emacs
2. All files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c89
3. All files should end with a new line
4. A README.md file, at the root of the folder of the project is mandatory
5. Code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
6. Maximum of one global variable is allowed
7. No more than 5 functions per file
8. The prototypes of all functions should be included in header file called monty.h
9. All header files should be include guarded
# More Info
## Data structures
The following data structures should be used for this project and included in the header file.

/**

 * struct stack_s - doubly linked list representation of a stack (or queue)
 
 * @n: integer
 
 * @prev: points to the previous element of the stack (or queue)
 
 * @next: points to the next element of the stack (or queue)
 
 *
 
 * Description: doubly linked list node structure
 
 * for stack, queues, LIFO, FIFO  
 
 */  

typedef struct stack_s  

{  

        int n;  

        struct stack_s *prev;  

        struct stack_s *next;  

} stack_t;  

/**

 * struct instruction_s - opcode and its function

 * @opcode: the opcode
 
 * @f: function to handle the opcode
 
 *
 
 * Description: opcode and its function
 
 * for stack, queues, LIFO, FIFO
 
 */

typedef struct instruction_s

{

        char *opcode;
        
        void (*f)(stack_t **stack, unsigned int line_number);

} instruction_t;
# Copyright - Plagiarism
Any form of plagiarism is strictly forbidden and will result in removal from the program.
