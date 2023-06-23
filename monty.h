#ifndef MONTY_INTERPRETER_H
#define MONTY_INTERPRETER_H

#include <stdio.h>

/* Doubly linked list node structure */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

stack_t *createStack(void);
void push(stack_t **stack, int value);
void pall(stack_t **stack, unsigned int line_number);
void freeStack(stack_t **stack);
void processFile(const char *file_path);
void parseInstruction(char *line, unsigned int line_number, stack_t **stack);
void exeinst(char *opcode, unsigned int line_number, stack_t **stack);
void pint(stack_t **stack, unsigned int line_number);


#endif /* MONTY_INTERPRETER_H */
