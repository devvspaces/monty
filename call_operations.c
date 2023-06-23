#include "monty.h"

/**
 * call_opcode - executes called stack instructions
 *
 * @stack: pointer to top node of a stack
 * @oper: string copy of stack instruction
 * @span: the current file span number calling instruction
 */
void call_opcode(stack_t **stack, char *oper, unsigned int span)
{
	int c;

	instruction_t all_opers[] = {
		{"push", op_push},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{"stack", set_op_flow},
		{"queue", set_queue},
		{NULL, NULL}};

	for (c = 0; all_opers[c].opcode != NULL; c++)
		if (strcmp(oper, all_opers[c].opcode) == 0)
		{
			all_opers[c].f(stack, span);
			return;
		}
	fprintf(stderr, "L%u: unknown instruction %s\n", span, oper);
	exit(EXIT_FAILURE);
}
