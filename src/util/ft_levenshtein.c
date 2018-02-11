/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_levenshtein.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 12:48:22 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/11 17:29:50 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int		min_3(unsigned int a, unsigned int b, unsigned int c)
{
	if (a < b)
	{
		if (a < c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b < c)
			return (b);
		else
			return (c);
	}
}

/*
** THe Levenshtein distance is a string metric for measuring the difference
** between two sequences.
** 0 == exactly the same string
** 1 == one modification
** ...
*/

int				ft_levenshtein(char *s1, char *s2, size_t s1len, size_t s2len)
{
	unsigned int x;
	unsigned int y;
	unsigned int lastdiag;
	unsigned int olddiag;
	unsigned int column[s1len + 1];

	y = 0;
	while (++y <= s1len)
		column[y] = y;
	x = 0;
	while (++x <= s2len)
	{
		column[0] = x;
		y = 0;
		lastdiag = x - 1;
		while (++y <= s1len)
		{
			olddiag = column[y];
			column[y] = (unsigned int)min_3(column[y] + 1, column[y - 1] + 1,
			lastdiag + (s1[y - 1] == s2[x - 1] ? 0 : 1));
			lastdiag = olddiag;
		}
	}
	return (column[s1len]);
}
