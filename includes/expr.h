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

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

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

#endif
