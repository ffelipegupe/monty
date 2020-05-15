#include "monty.h"
extgl glob = {NULL, NULL, NULL};

/**
 * main - main function
 * @argc: argument count.
 * @argv: arguments vector.
 * Return: EXIT SUCcESS on success; EXIT FAILURE otherwise.
*/

int main(int argc, char *argv[])
{
	size_t len = 32;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	glob.fil = fopen(argv[1], "r");
	if (!glob.fil)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&glob.buf, &len, glob.fil)) != EOF)
	{
		line_number++;
		parse(glob.buf, &stack, line_number);
	}
	free_list(stack);
	exit(EXIT_SUCCESS);
}
