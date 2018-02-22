/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bundle_funcs_2.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 21:11:04 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 21:11:04 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "expr.h"

int land(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '&' && *(*s + 1) == '&' && OPEND(*(*s + 2)))
		*a = ((*i = **a && *eval((*s += 2, s), (*p) - 1)), i);
	else
		return (1);
	return (0);
}

int lor(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '|' && *(*s + 1) == '|' && OPEND(*(*s + 2)))
		*a = ((*i = **a || *eval((*s += 2, s), (*p) - 1)), i);
	else
		return (1);
	return (0);
}

int conditionalex(char **s, int **a, int *i)
{
	int	*b;
	int	*c;

	if (**s == '?' && *(*s + 1) == ':' && OPEND(*(*s + 2)))
	{
		b = eval((*s += 2, s), MAX);
		*a = ((*i = **a ? **a : *b), i);
	}
	else if (**s == '?' && OPEND(*(*s + 1)))
	{
		b = eval((++*s, s), MAX);
		while (ISWS(**s))
			++*s;
		c = eval((++*s, s), MAX);
		*a = ((*i = **a ? *b : *c), i);
	}
	else
		return (1);
	return (0);
}

int assignex(char **s, t_priority *p, int **a)
{
	if (**s == '=' && OPEND(*(*s + 1)))
		**a = GET_NEXT;
	else
		return (1);
	return (0);
}

int exprex(char **s, t_priority *p, int **a)
{
	if (**s == ',' && OPEND(*(*s + 1)))
		*a = eval((++*s, s), (*p) - 1);
	else
		return (1);
	return (0);
}