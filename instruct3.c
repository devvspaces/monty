#include "monty.h"

/**
 * op_mod - rest of the division of the second top by the top
 * @stack: pointer to the top node of stack
 * @span: the current file span number calling instruction
 */
void op_mod(stack_t **stack, unsigned int span)
{
	int n;

	if (var.s_len < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", span);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	op_pop(stack, span);
	if (n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", span);
		exit(EXIT_FAILURE);
	}
	(*stack)->n %= n;
}

/**
 * op_pchar - prints the char at the top of the stack
 * @stack: pointer to the top node of stack
 * @span: the current file span number calling instruction
 */
void op_pchar(stack_t **stack, unsigned int span)
{
	int ch;

	if (var.s_len < 1)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", span);
		exit(EXIT_FAILURE);
	}
	ch = (*stack)->n;
	if (!isascii(ch))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", span);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ch);
}

/**
 * op_pstr - prints the string starting at the top of the stack
 * @stack: pointer to the top node of stack
 * @span: the current file span number calling instruction
 */
void op_pstr(stack_t **stack, unsigned int span __attribute__((unused)))
{
	stack_t *tmp;
	int ch;

	tmp = *stack;
	while (tmp != NULL)
	{
		ch = tmp->n;
		if (!isascii(ch) || ch == 0)
			break;
		putchar(ch);
		tmp = tmp->next;
		if (tmp == *stack)
			break;
	}
	putchar('\n');
}

/**
 * op_rotl - rotl rotates the stack to the top
 * @stack: pointer to the top node of stack
 * @span: the current file span number calling instruction
 */
void op_rotl(stack_t **stack, unsigned int span __attribute__((unused)))
{
	if (*stack)
		*stack = (*stack)->next;
}

/**
 * op_rotr - rotr rotates the stack to the bottom
 * @stack: pointer to the top node of stack
 * @span: the current file span number calling instruction
 */
void op_rotr(stack_t **stack, unsigned int span __attribute__((unused)))
{
	if (*stack)
		*stack = (*stack)->prev;
}
