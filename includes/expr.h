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
# include <ctype.h>

# define ISWS(c) ((c) == ' ' || ((c) >= '\t' && (c) <= '\r'))
# define OPEND(c) (ft_isdigit(c) || ISWS(c) || (c) == '$')
# define GET_NEXT *eval((++*s, s), (*p) - 1)

extern int		g_stack[4096];
extern int		g_idx;
extern int		g_ustack[4096];

typedef enum	e_priority
{
	PRIMARY = 0,
	UNARY,
	MULTIPLICATIVE,
	ADDITIVE,
	SHIFT,
	RELATIONAL,
	EQUALITY,
	AND,
	XOR,
	OR,
	LAND,
	LOR,
	CONDITIONAL,
	ASSIGN,
	EXPR,
	MAX = EXPR
}				t_priority;

int				*eval(char **s, t_priority p);
int				eval_expr(char *str);
int				*primary(char **s, int *a);
int				*unary(char **s, t_priority *p, int *a);
int				multiplicative(char **s, t_priority *p, int **a, int *i);
int				additive(char **s, t_priority *p, int **a, int *i);
int				shift(char **s, t_priority *p, int **a, int *i);
int				relational(char **s, t_priority *p, int **a, int *i);
int				equality(char **s, t_priority *p, int **a, int *i);
int				andex(char **s, t_priority *p, int **a, int *i);
int				xorex(char **s, t_priority *p, int **a, int *i);
int				orex(char **s, t_priority *p, int **a, int *i);
int				land(char **s, t_priority *p, int **a, int *i);
int				lor(char **s, t_priority *p, int **a, int *i);
int				conditionalex(char **s, int **a, int *i);
int				assignex(char **s, t_priority *p, int **a);
int				exprex(char **s, t_priority *p, int **a);
int 			validate_simple_exp(char *expr);

#endif
