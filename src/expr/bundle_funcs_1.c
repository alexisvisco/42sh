/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bundle_funcs_1.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 21:09:44 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 21:09:44 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "expr.h"

int relational(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '<' && OPEND(*(*s + 1)))
		*a = ((*i = **a < GET_NEXT), i);
	else if (**s == '>' && OPEND(*(*s + 1)))
		*a = ((*i = **a > GET_NEXT), i);
	else if (**s == '<' && *(*s + 1) == '=' && OPEND(*(*s + 2)))
		*a = ((*i = **a <= *eval((*s += 2, s), (*p) - 1)), i);
	else if (**s == '>' && *(*s + 1) == '=' && OPEND(*(*s + 2)))
		*a = ((*i = **a >= *eval((*s += 2, s), (*p) - 1)), i);
	else
		return (1);
	return (0);
}

int equality(char **s, t_priority *p, int **a, int *i)
{

	if (**s == '=' && *(*s + 1) == '=' && OPEND(*(*s + 2)))
		*a = ((*i = **a == *eval((*s += 2, s), (*p) - 1)), i);
	else if (**s == '!' && *(*s + 1) == '=' && OPEND(*(*s + 2)))
		*a = ((*i = **a != *eval((*s += 2, s), (*p) - 1)), i);
	else
		return (1);
	return (0);
}

int andex(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '&' && OPEND(*(*s + 1)))
		*a = ((*i = **a & GET_NEXT), i);
	else
		return (1);
	return (0);
}

int xorex(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '^' && OPEND(*(*s + 1)))
		*a = ((*i = **a ^ GET_NEXT), i);
	else
		return (1);
	return (0);
}

int orex(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '|' && OPEND(*(*s + 1)))
		*a = ((*i = **a | GET_NEXT), i);
	else
		return (1);
	return (0);
}