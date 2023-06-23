#include "monty.h"

/**
 * op_push - pushes a data/number to stack
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void op_push(stack_t **stack, unsigned int line)
{
	char *str;
	int num;

	str = strtok(NULL, "\n\t\r ");
	if (str == NULL || is_digit(str))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	num = atoi(str);
	if (!add_node(stack, num))
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.len_stack++;
}

/**
 * op_pall - prints all of the data/number in the stack
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void op_pall(stack_t **stack, unsigned int line)
{
	stack_t *head;

	(void)line;
	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		if (head == *stack)
			return;
	}
}

/**
 * op_pint - prints the value at the top of the stack
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void op_pint(stack_t **stack, unsigned int line)
{
	stack_t *head = *stack;
	if (var.len_stack == 0)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}

/**
 * op_pop - removes the top element of the stack
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void op_pop(stack_t **stack, unsigned int line)
{
	stack_t *pop = *stack;

	if (var.len_stack == 0)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
	if (var.len_stack != 1)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(pop);
	var.len_stack--;
}

/**
 * op_swap - swaps the top two elements of the stack
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void op_swap(stack_t **stack, unsigned int line __attribute__((unused)))
{
	stack_t *tmp;

	if (var.len_stack < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if (var.len_stack == 2)
	{
		*stack = (*stack)->next;
		return;
	}
	tmp = (*stack)->next;
	tmp->prev = (*stack)->prev;
	(*stack)->prev->next = tmp;
	(*stack)->prev = tmp;
	(*stack)->next = tmp->next;
	tmp->next->prev = *stack;
	tmp->next = *stack;
	*stack = tmp;
}