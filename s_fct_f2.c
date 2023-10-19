#include "monty.h"
#include <stdio.h>

/**
 * f_open - open the file
 * @f_name: path of the file
 * Return: empty
 */

void f_open(char *f_name)
{
	FILE *desc_f = fopen(f_name, "r");

	if (f_name == NULL || desc_f == NULL)
		print_err_1(2, f_name);

	f_read(desc_f);
	fclose(desc_f);
}


/**
 * f_read - reads a file
 * @desc_f: pointer to file descriptor
 * Return: EMPTY
 */

void f_read(FILE *desc_f)
{
	int n_n_le, rndm = 0;
	char *bfffr = NULL;
	size_t lgth = 0;

	for (n_n_le = 1; getline(&bfffr, &lgth, desc_f) != -1; n_n_le++)
	{
		rndm = sep_l(bfffr, n_n_le, rndm);
	}
	free(bfffr);
}


/**
 * sep_l - token separete lines
 * @bfffr: buffer its a line for the file
 * @n_n_le: muber of line
 * @rndm:  type (stack or queue)
 * Return: int
 */

int sep_l(char *bfffr, int n_n_le, int rndm)
{
	char *code_opert, *stckge;
	const char *n_lINe = "\n ";

	if (bfffr == NULL)
		print_err_1(4);

	code_opert = strtok(bfffr, n_lINe);
	if (code_opert == NULL)
		return (rndm);
	stckge = strtok(NULL, n_lINe);

	if (strcmp(code_opert, "stack") == 0)
		return (0);
	if (strcmp(code_opert, "queue") == 0)
		return (1);

	fct_s(code_opert, stckge, n_n_le, rndm);
	return (rndm);
}

/**
 * fct_s - search and find the fuction
 * @code_opert: the opcode
 * @stckge: arguments
 * @rndm:  type stack or queue
 * @n_l: number of line
 * Return: empty
 */
void fct_s(char *code_opert, char *stckge, int n_l, int rndm)
{
	int k;
	int fllg;

	instruction_t fct_lst[] = {
		{"push", push_ll},
		{"pall", prnt_st},
		{"pint", pt},
		{"mul", MuL},
		{"mod", MoD},
		{"pchar", print_c},
		{"pstr", print_string},
		{"rotl", rot_s_t},
		{"rotr", rot_s_b},
		{"pop", del_tp},
		{"nop", do_none},
		{"swap", SwaP},
		{"add", aDD},
		{"sub", SUb},
		{"div", DIVs},

		{NULL, NULL}
	};

	if (code_opert[0] == '#')
		return;

	for (fllg = 1, k = 0; fct_lst[k].opcode != NULL; k++)
	{
		if (strcmp(code_opert, fct_lst[k].opcode) == 0)
		{
			fct_c(fct_lst[k].f, code_opert, stckge, n_l, rndm);
			fllg = 0;
		}
	}
	if (fllg == 1)
		print_err_1(3, n_l, code_opert);
}


/**
 * fct_c - the function call
 * @fct_ptr: pointer to this function
 * @strg_oper: a string
 * @insd: string
 * @n_l: number of line
 * @rndm: type stack or queue
 * Return: empty
 */

void fct_c(s_fct_f fct_ptr, char *strg_oper, char *insd, int n_l, int rndm)
{
	stack_t *new_nd;
	int fllg;
	int k;

	fllg = 1;
	if (strcmp(strg_oper, "push") == 0)
	{
		if (insd != NULL && insd[0] == '-')
		{
			insd = insd + 1;
			fllg = -1;
		}
		if (insd == NULL)
			print_err_1(5, n_l);
		for (k = 0; insd[k] != '\0'; k++)
		{
			if (isdigit(insd[k]) == 0)
				print_err_1(5, n_l);
		}
		new_nd = nd_cr(atoi(insd) * fllg);
		if (rndm == 0)
			fct_ptr(&new_nd, n_l);
		if (rndm == 1)
			qu_ad(&new_nd, n_l);
	}
	else
		fct_ptr(&hd, n_l);
}
