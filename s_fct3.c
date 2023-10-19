#include "monty.h"

/**
 * SUb - subtracts the top from the second in stack
 * @tooop: doublr pointer to the top
 * @num_l: int
 * Return: empty
 */
void SUb(stack_t **tooop, unsigned int num_l)
{
	int somme;

	if (tooop == NULL || *tooop == NULL || (*tooop)->next == NULL)

		print_err_2(8, num_l, "sub");


	(*tooop) = (*tooop)->next;
	somme = (*tooop)->n - (*tooop)->prev->n;
	(*tooop)->n = somme;
	free((*tooop)->prev);
	(*tooop)->prev = NULL;
}


/**
 * DIVs - devide the second top el by the top el of stack
 * @t_s: double pointer to the top of stack
 * @num_l: int (number of line)
 * Return: empty
 */
void DIVs(stack_t **t_s, unsigned int num_l)
{
	int somme;

	if (t_s == NULL || *t_s == NULL || (*t_s)->next == NULL)
		print_err_2(8, num_l, "div");

	if ((*t_s)->n == 0)
		print_err_2(9, num_l);
	(*t_s) = (*t_s)->next;
	somme = (*t_s)->n / (*t_s)->prev->n;
	(*t_s)->n = somme;
	free((*t_s)->prev);
	(*t_s)->prev = NULL;
}

/**
 * MuL - multiplies the 2 top with the top el of the stack.
 * @t_ofstack: double pointer to the top
 * @num_l: integer(number line)
 * Return: empty
 */
void MuL(stack_t **t_ofstack, unsigned int num_l)
{
	int sum;

	if (t_ofstack == NULL || *t_ofstack == NULL || (*t_ofstack)->next == NULL)
		print_err_2(8, num_l, "mul");

	(*t_ofstack) = (*t_ofstack)->next;
	sum = (*t_ofstack)->n * (*t_ofstack)->prev->n;
	(*t_ofstack)->n = sum;
	free((*t_ofstack)->prev);
	(*t_ofstack)->prev = NULL;
}


/**
 * MoD - mod the 2 top with the top elment of the stack
 * @t_ofstack: double pointer to the top
 * @num_l: int (line number)
 * Return: empty
 */
void MoD(stack_t **t_ofstack, unsigned int num_l)
{
	int sum;

	if (t_ofstack == NULL || *t_ofstack == NULL || (*t_ofstack)->next == NULL)

		more_err(8, num_l, "mod");


	if ((*t_ofstack)->n == 0)
		more_err(9, num_l);
	(*t_ofstack) = (*t_ofstack)->next;
	sum = (*t_ofstack)->n % (*t_ofstack)->prev->n;
	(*t_ofstack)->n = sum;
	free((*t_ofstack)->prev);
	(*t_ofstack)->prev = NULL;
}
