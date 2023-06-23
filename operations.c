#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * createStack - Creates an empty stack.
 *
 * Return: A pointer to the newly created stack (empty).
 */
stack_t *createStack()
{
	stack_t *stack = NULL;

	return (stack);
}

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the stack (top of the stack).
 * @value: The value to be pushed to the stack.
 *
 * Description: The push opcode pushes an element to the stack.
 * It creates a new node with the given value and adds it to
 * the top of the stack.
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the stack (top of the stack).
 * @line_number: The line number where the instruction appears.
 *
 * Description: The pall opcode prints all the values on the stack,
 * starting from the top of the stack.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
}

/**
 * freeStack - Frees the memory allocated for the stack.
 * @stack: Double pointer to the stack (top of the stack).
 *
 * Description: The freeStack function frees the memory allocated
 * for the stack,deallocating all the nodes in the stack.
 */
void freeStack(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		stack_t *temp = current;

		current = current->next;

		free(temp);
	}
}
