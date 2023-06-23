#include "monty.h"

/**
 * is_digit - checks string is only digit
 * @str: string input argument
 * Return: 0 is only digit or 1 not digit
 */

int is_digit(char *str)
{
	int c;

	for (c = 0; str[c]; c++)
	{
		if (str[c] == '-' && c == 0)
			continue;
		if (isdigit(str[c]) == 0)
			return (1);
	}
	return (0);
}

/**
 * set_queue - sets the format of the data to a queue (FIFO)
 * @stack: top of the stack
 * @span: script span number
 */
void set_queue(stack_t **stack, unsigned int span)
{
	(void)stack;
	(void)span;
	var.q_len = FIFO;
}

/**
 * set_op_flow - sets the format of the data to a stack (LIFO)
 *
 * @stack: top of the stack
 * @span: script span number
 */
void set_op_flow(stack_t **stack, unsigned int span)
{
	(void)stack;
	(void)span;
	var.q_len = LIFO;
}
