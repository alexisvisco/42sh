/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   expr.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 11:15:54 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 11:15:54 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef EXPR_H
# define EXPR_H

# include <stdlib.h>
# include <stdio.h>

#define IS_OP(c) (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
#define IS_LEFT(c) (c != '^')

typedef struct  stack
{
	char        *data[4096];
	int         top;
	char        *(*pop)(struct stack *);
	char        *(*peek)(struct stack *);
	void        (*push)(struct stack *, char *);
}               t_stack;

typedef struct  stack_i
{
	int       	data[4096];
	int         top;
	int        	(*pop)(struct stack_i *);
	int        	(*peek)(struct stack_i *);
	void        (*push)(struct stack_i *, int);
}               t_stack_i;

typedef struct	result_npi
{
	int 		res;
	char 		*error;
}				t_res_npi;

void			init_stack(t_stack *stack);
void			init_stack_i(t_stack_i *stack);

char    		*infix2postfix(char *str);
void 			postfix2result(char *str, t_res_npi *res);

#endif
