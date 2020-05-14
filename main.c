#include "monty.h"
stack_t *stack = NULL;

/**
 * main - main function
 * @argc: argument count
 * @argv: arguments vector
 * Return: 1
*/
int main(int argc, const char *argv[])
{
	FILE *file;
	char *buf = NULL;
	size_t buf_size = 80;
	int j = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (argv[1] == NULL)
		return (0);
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buf, &buf_size, file) != -1)
	{
		if (buf[0] == '#')
			continue;
		printErrors(callFunction(buf, j), j, buf, file);
		j++;
	}
	free_(buf, file);
	return (0);
}

/**
 * free_ - function that frees the stack/queue
 * @buf: buffer to free
 * @file: File
*/
void free_(char *buf, stack_t **stack, FILE *file)
{
	free(buf);
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = temp->next;
		free(temp);
	}
	free(*stack);
	fclose(file);
}

/**
 * free_pointer - function that frees a double pointer
 * @tok : to be free
 * @height : size of the mtr
*/
void free_pointer(char **tok, int height)
{
	int i = 0;

	for (i = 0; i < height; i++)
		if (tok[i] != NULL)
		{
			free(tok[i]);
		}
	free(tok);
}