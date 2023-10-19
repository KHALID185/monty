#include "monty.h"
stack_t *hd = NULL;

/**
 * nd_cr - node create
 * @value: the value inside node
 * Return: a stack
 */
stack_t *nd_cr(int value)
{
	stack_t *new_nd;

	new_nd = malloc(sizeof(stack_t));
	if (new_nd == NULL)
		print_err_1(4);
	new_nd->next = NULL;
	new_nd->prev = NULL;
	new_nd->n = value;
	return (new_nd);
}

/**
 * nd_free - free node
 * Return: empty
 */
void nd_free(void)
{
	stack_t *garage;

	if (hd == NULL)
		return;

	while (hd != NULL)
	{
		garage = hd;
		hd = hd->next;
		free(garage);
	}
}


/**
 * qu_ad - add node
 * @n_d: pointer to the new node on the queue
 * @num_ln: number of the line
 */
void qu_ad(stack_t **n_d, __attribute__((unused))unsigned int num_ln)
{
	stack_t *garage;

	if (n_d == NULL || *n_d == NULL)
		exit(EXIT_FAILURE);
	if (hd == NULL)
	{
		hd = *n_d;
		return;
	}
	garage = hd;
	while (garage->next != NULL)
		garage = garage->next;

	garage->next = *n_d;
	(*n_d)->prev = garage;

}
