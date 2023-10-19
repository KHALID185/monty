#include "monty.h"

/**
 * do_none - doesn’t do anything.
 * @tooop: double pointer to the top element
 * @num_l: integer
 */
void do_none(stack_t **tooop, unsigned int num_l)
{
	(void)tooop;
	(void)num_l;
}


/**
 * SwaP - Swap the first 2 el in stack
 * @tooop: double pointer
 * @num_l: integer
 */
void SwaP(stack_t **tooop, unsigned int num_l)
{
	stack_t *garage;

	if (tooop == NULL || *tooop == NULL || (*tooop)->next == NULL)
		print_err_2(8, num_l, "swap");
	garage = (*tooop)->next;
	(*tooop)->next = garage->next;
	if (garage->next != NULL)
		garage->next->prev = *tooop;
	garage->next = *tooop;
	(*tooop)->prev = garage;
	garage->prev = NULL;
	*tooop = garage;
}

/**
 * aDD - adds thetwo elements of the stack of the top.
 * @tooop: double pointer to the top element
 * @num_l: int (number of the line)
 */
void aDD(stack_t **tooop, unsigned int num_l)
{
	int somme;

	if (tooop == NULL || *tooop == NULL || (*tooop)->next == NULL)
		print_err_2(8, num_l, "add");

	(*tooop) = (*tooop)->next;
	somme = (*tooop)->n + (*tooop)->prev->n;
	(*tooop)->n = somme;
	free((*tooop)->prev);
	(*tooop)->prev = NULL;
}


