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

#define REL1 (*i = **a < GET_NEXT), i
#define REL2 (*i = **a > GET_NEXT), i
#define REL3 (*i = **a <= *eval((*s += 2, s), (*p) - 1)), i
#define REL4 (*i = **a >= *eval((*s += 2, s), (*p) - 1)), i
#define EQU1 (*i = **a == *eval((*s += 2, s), (*p) - 1)), i
#define EQU2 (*i = **a != *eval((*s += 2, s), (*p) - 1)), i
#define AND1 (*i = **a & GET_NEXT), i
#define XOREX (*i = **a ^ GET_NEXT), i
#define OREX (*i = **a | GET_NEXT), i

int		relational(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '<' && OPEND(*(*s + 1)))
		*a = (REL1);
	else if (**s == '>' && OPEND(*(*s + 1)))
		*a = (REL2);
	else if (**s == '<' && *(*s + 1) == '=' && OPEND(*(*s + 2)))
		*a = (REL3);
	else if (**s == '>' && *(*s + 1) == '=' && OPEND(*(*s + 2)))
		*a = (REL4);
	else
		return (1);
	return (0);
}

int		equality(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '=' && *(*s + 1) == '=' && OPEND(*(*s + 2)))
		*a = (EQU1);
	else if (**s == '!' && *(*s + 1) == '=' && OPEND(*(*s + 2)))
		*a = (EQU2);
	else
		return (1);
	return (0);
}

int		andex(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '&' && OPEND(*(*s + 1)))
		*a = (AND1);
	else
		return (1);
	return (0);
}

int		xorex(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '^' && OPEND(*(*s + 1)))
		*a = (XOREX);
	else
		return (1);
	return (0);
}

int		orex(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '|' && OPEND(*(*s + 1)))
		*a = (OREX);
	else
		return (1);
	return (0);
}
