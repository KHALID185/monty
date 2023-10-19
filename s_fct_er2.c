#include "monty.h"

/**
 * print_err_2 - print the error message
 * @case_error: The error case
 * Return: empty
 */
void print_err_2(int case_error, ...)
{
	va_list lsst;
	char *ptr;
	int n_line;

	va_start(lsst, case_error);
	switch (case_error)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(lsst, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(lsst, int));
			break;
		case 8:
			n_line = va_arg(lsst, unsigned int);
			ptr = va_arg(lsst, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", n_line, ptr);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(lsst, unsigned int));
			break;
		default:
			break;
	}
	nd_free();
	exit(EXIT_FAILURE);
}

/**
 * print_err_3 - print the error
 * @case_error: case error
 * Return: empty
 */
void print_err_3(int case_error, ...)
{
	va_list lsst;
	int n_line;

	va_start(lsst, case_error);
	n_line = va_arg(lsst, int);
	switch (case_error)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", n_line);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", n_line);
			break;
		default:
			break;
	}
	nd_free();
	exit(EXIT_FAILURE);
}
