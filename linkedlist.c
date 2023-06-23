#include "monty.h"

/**
 * add_node - add a new node to a circular linked list
 *
 * @stack: double pointer to the beginning of the circular linked list
 * @n: value to add to the new node
 *
 * Return: pointer to the new node if successful else NULL
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (*stack == NULL)
	{
		new->prev = new;
		new->next = new;
	}
	else
	{
		(*stack)->prev->next = new;
		new->prev = (*stack)->prev;
		(*stack)->prev = new;
		new->next = *stack;
	}
	if (var.q_len == LIFO || var.s_len == 0)
		*stack = new;
	return (new);
}
