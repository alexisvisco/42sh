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

#define LAND (*i = **a && *eval((*s += 2, s), (*p) - 1)), i
#define LOR (*i = **a || *eval((*s += 2, s), (*p) - 1)), i
#define CEX (*i = **a ? **a : *b), i
#define CEX2 (*i = **a ? *b : *c), i

int		land(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '&' && *(*s + 1) == '&' && OPEND(*(*s + 2)))
		*a = (LAND);
	else
		return (1);
	return (0);
}

int		lor(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '|' && *(*s + 1) == '|' && OPEND(*(*s + 2)))
		*a = (LOR);
	else
		return (1);
	return (0);
}

int		conditionalex(char **s, int **a, int *i)
{
	int	*b;
	int	*c;

	if (**s == '?' && *(*s + 1) == ':' && OPEND(*(*s + 2)))
	{
		*s += 2;
		b = eval(s, MAX);
		*a = (CEX);
	}
	else if (**s == '?' && OPEND(*(*s + 1)))
	{
		++*s;
		b = eval(s, MAX);
		while (ISWS(**s))
			++*s;
		++*s;
		c = eval(s, MAX);
		*a = (CEX2);
	}
	else
		return (1);
	return (0);
}

int		assignex(char **s, t_priority *p, int **a)
{
	if (**s == '=' && OPEND(*(*s + 1)))
		**a = GET_NEXT;
	else
		return (1);
	return (0);
}

int		exprex(char **s, t_priority *p, int **a)
{
	if (**s == ',' && OPEND(*(*s + 1)))
	{
		++*s;
		*a = eval(s, (*p) - 1);
	}
	else
		return (1);
	return (0);
}
