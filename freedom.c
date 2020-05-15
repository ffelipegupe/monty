include "monty.h"
/**
 * free_list - function that frees a list.
 * @stack: list to be freed.
 *
 * Return: nothing.
 */

void free_list(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	fclose(glob.fil);
	free(glob.buf);
}