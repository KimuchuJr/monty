#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define MAX_LINE_LENGTH 100
/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Description: The main function parses the command-line arguments,
 * validates the usage, and calls the processFile function to interpret
 * and execute the Monty byte code file.
 *
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	processFile(argv[1]);

	return (EXIT_SUCCESS);
}

/**
 * processFile - Processes the Monty byte code file.
 * @file_path: The path to the file containing Monty byte code.
 *
 * Description: The processFile function reads the Monty byte code file
 * line by line, parsing the instructions and
 * executing the corresponding opcodes.
 */
void processFile(const char *file_path)
{
	FILE *file;
	char line[MAX_LINE_LENGTH];
	unsigned int line_number = 0;
	stack_t *stack;

	file = fopen(file_path, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}

	stack = createStack();

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		parseInstruction(line, line_number, &stack);
	}

	fclose(file);
	freeStack(&stack);
}

/**
 * parseInstruction - Parses the instruction from the input line.
 * @line: The input line containing the instruction.
 * @line_number: The line number where the instruction appears.
 * @stack: Double pointer to the stack (top of the stack).
 *
 * Description: The parseInstruction function parses the instruction
 * and executes it by calling the executeInstruction function.
 */
void parseInstruction(char *line, unsigned int line_number, stack_t **stack)
{
	char *opcode = strtok(line, " \t\n");

	if (opcode == NULL || opcode[0] == '#')
	{
		return;
	}

	exeinst(opcode, line_number, stack);
}
/**
 * exeinst - Executes the instruction based on the given opcode.
 * @opcode: The opcode of the instruction to be executed.
 * @line_number: The line number where the instruction appears.
 * @stack: Double pointer to the stack (top of the stack).
 *
 * Description: The executeInstruction function performs the execution
 * based on the given opcode.
 */
void exeinst(char *opcode, unsigned int line_number, stack_t **stack)
{
	char *arg;
	int value;

	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, " \t\n");
		if (arg == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

		value = atoi(arg);

		push(stack, value);

	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
