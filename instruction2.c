#include "monty.h"

/**
 * op_add - adds the top two elements of the stack
 * @stack: pointer to the top node of stack
 * @span: the current file span number calling instruction
 */
void op_add(stack_t **stack, unsigned int span)
{
	int n = 0;

	if (var.s_len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", span);
		exit(EXIT_FAILURE);
	}
	n += (*stack)->n;
	op_pop(stack, span);
	(*stack)->n += n;
}

/**
 * op_nop - nop doesn’t do anything
 * @stack: pointer to the top node of stack
 * @span: the current file span number calling instruction
 */
void op_nop(stack_t **stack __attribute__((unused)), unsigned int span)
{
	(void)span;
}

/**
 * op_sub - sub subtracts the top from the second top element
 * @stack: pointer to the top node of stack
 * @span: the current file span number calling instruction
 */
void op_sub(stack_t **stack, unsigned int span)
{
	int n;

	if (var.s_len < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", span);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	op_pop(stack, span);
	(*stack)->n -= n;
}

/**
 * op_div - divides the second top by the top element of the stack
 * @stack: pointer to the top node of stack
 * @span: the current file span number calling instruction
 */
void op_div(stack_t **stack, unsigned int span)
{
	int n;

	if (var.s_len < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", span);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	op_pop(stack, span);
	if (n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", span);
		exit(EXIT_FAILURE);
	}
	(*stack)->n /= n;
}

/**
 * op_mul - multiplies the second top with the top element
 * @stack: pointer to the top node of stack
 * @span: the current file span number calling instruction
 */
void op_mul(stack_t **stack, unsigned int span)
{
	int n;

	if (var.s_len < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", span);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	op_pop(stack, span);
	(*stack)->n *= n;
}
