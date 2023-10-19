#include "monty.h"

/**
 * print_c - print character
 * @top_s: double pointer to the top
 * @n_line: number of line integer
 * Return: empty
 */
void print_c(stack_t **top_s, unsigned int n_line)
{
	int nembre_asci;

	if (top_s == NULL || *top_s == NULL)
		print_err_3(11, n_line);

	nembre_asci = (*top_s)->n;
	if (nembre_asci < 0 || nembre_asci > 127)
		print_err_3(10, n_line);
	printf("%c\n", nembre_asci);
}

/**
 * print_string - print a string
 * @top_s: double pointer to the top
 * @line_n: line number int
 * Return: empty
 */
void print_string(stack_t **top_s, __attribute__((unused))unsigned int line_n)
{
	int nembre_asci;
	stack_t *garage;

	if (top_s == NULL || *top_s == NULL)
	{
		printf("\n");
		return;
	}

	garage = *top_s;
	while (garage != NULL)
	{
		nembre_asci = garage->n;
		if (nembre_asci <= 0 || nembre_asci > 127)
			break;
		printf("%c", nembre_asci);
		garage = garage->next;
	}
	printf("\n");
}

/**
 * rot_s_t -  rotates the stack to the top.
 * @top_s: double pointer to the top
 * @line_n: number line integer
 */
void rot_s_t(stack_t **top_s, __attribute__((unused))unsigned int line_n)
{
	stack_t *garage;

	if (top_s == NULL || *top_s == NULL || (*top_s)->next == NULL)
		return;

	garage = *top_s;
	while (garage->next != NULL)
		garage = garage->next;

	garage->next = *top_s;
	(*top_s)->prev = garage;
	*top_s = (*top_s)->next;
	(*top_s)->prev->next = NULL;
	(*top_s)->prev = NULL;
}


/**
 * rot_s_b - rotates the stack to the bottom.
 * @top_s: double pointer to the top
 * @line_n: integer
 */
void rot_s_b(stack_t **top_s, __attribute__((unused))unsigned int line_n)
{
	stack_t *garage;

	if (top_s == NULL || *top_s == NULL || (*top_s)->next == NULL)
		return;

	garage = *top_s;

	while (garage->next != NULL)
		garage = garage->next;

	garage->next = *top_s;
	garage->prev->next = NULL;
	garage->prev = NULL;
	(*top_s)->prev = garage;
	(*top_s) = garage;
}
