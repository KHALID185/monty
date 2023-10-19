#ifndef MONTY_H
#define MONTY_H

#define gd

#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *hd;
typedef void (*s_fct_f)(stack_t **, unsigned int);


void push_ll(stack_t **n_n, __attribute__((unused))unsigned int l_c);
void prnt_st(stack_t **toop, unsigned int number_l_opc);
void del_tp(stack_t **t_s, unsigned int number_l_opc);
void pt(stack_t **ts, unsigned int number_l_opc);
void do_none(stack_t **tooop, unsigned int num_l);
void SwaP(stack_t **tooop, unsigned int num_l);
void aDD(stack_t **tooop, unsigned int num_l);
void MuL(stack_t **t_ofstack, unsigned int num_l);
void MoD(stack_t **t_ofstack, unsigned int num_l);
void DIVs(stack_t **t_s, unsigned int num_l);
void SUb(stack_t **tooop, unsigned int num_l);

void print_err_1(int case_error, ...);
void print_err_2(int case_error, ...);
void print_err_3(int case_error, ...);
void print_string(stack_t **top_s, __attribute__((unused))unsigned int line_n);

void print_c(stack_t **top_s, unsigned int n_line);
void rot_s_t(stack_t **top_s, __attribute__((unused))unsigned int line_n);
void rot_s_b(stack_t **top_s, __attribute__((unused))unsigned int line_n);

void f_open(char *f_name);
void f_read(FILE *desc_f);
void fct_s(char *code_opert, char *stckge, int n_l, int rndm);
int sep_l(char *bfffr, int n_n_le, int rndm);
void fct_c(s_fct_f, char *, char *, int, int);
stack_t *nd_cr(int value);
void nd_free(void);
void qu_ad(stack_t **n_d, __attribute__((unused))unsigned int num_ln);


#endif MONTY_H
