#include "monty.h"

/**
 * print_err_1 - Print the error message
 * @case_error: the error case
 * Return: empty
 */
void print_err_1(int case_error, ...)
{
	va_list lsst;
	char *ptr;
	int n_line;

	va_start(lsst, case_error);
	switch (case_error)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(lsst, char *));
			break;
		case 3:
			n_line = va_arg(lsst, int);
			ptr = va_arg(lsst, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", n_line, ptr);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(lsst, int));
			break;
		default:
			break;
	}
	nd_free();
	exit(EXIT_FAILURE);
}
