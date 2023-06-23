#include <stdlib.h>
#include <stdio.h>
#include "monty.h"
/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the stack (top of the stack).
 * @line_number: The line number where the instruction appears.
 *
 * Description: The pint opcode prints the value at the top of the stack,
 * followed by a new line. If the stack is empty, it prints an error message
 * and exits with the status EXIT_FAILURE.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
