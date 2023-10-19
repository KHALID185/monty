#include "monty.h"

/**
 * push_ll - Adds a new element to the linkedlist
 * @n_n: the new node to add it to stack
 * @l_c: integer
 */
void push_ll(stack_t **n_n, __attribute__((unused))unsigned int l_c)
{
	stack_t *garage;

	if (n_n == NULL || *n_n == NULL)
		exit(EXIT_FAILURE);
	if (hd == NULL)
	{
		hd = *n_n;
		return;
	}
	garage = hd;
	hd = *n_n;
	hd->next = garage;
	garage->prev = hd;
}


/**
 * prnt_st - print all element of ll stack
 * @toop: double pointer to the top element of the stack
 * @number_l_opc: the number of the line
 */
void prnt_st(stack_t **toop, unsigned int number_l_opc)
{
	stack_t *garage;

	(void) number_l_opc;
	if (toop == NULL)
		exit(EXIT_FAILURE);
	garage = *toop;
	while (garage != NULL)
	{
		printf("%d\n", garage->n);
		garage = garage->next;
	}
}

/**
 * del_tp - delete at the toop of stack
 * @t_s: double pointer to the top of stack
 * @number_l_opc: int
 */
void del_tp(stack_t **t_s, unsigned int number_l_opc)
{
	stack_t *garage;

	if (t_s == NULL || *t_s == NULL)
		print_err_2(7, number_l_opc);
	garage = *t_s;
	*t_s = garage->next;
	if (*t_s != NULL)
		(*t_s)->prev = NULL;
	free(garage);
	garage = NULL;
}

/**
 * pt - Prints stacks of the top
 * @ts: double pointer to the top element
 * @number_l_opc: int number line
 */
void pt(stack_t **ts, unsigned int number_l_opc)
{
	if (ts == NULL || *ts == NULL)
		print_err_2(6, number_l_opc);
	printf("%d\n", (*ts)->n);
}
