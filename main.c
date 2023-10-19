#include "monty.h"


/**
 * main - function Entry
 * @ac: counter arg
 * @argv: vecteur arg
 * Return: 0 success
 */

int main(int ac, char *argv[])
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f_open(argv[1]);
	nd_free();
	return (0);
}
