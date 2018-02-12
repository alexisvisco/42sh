/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   odd_quote.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 14:47:56 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 15:36:19 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		which_quote(char *s)
{
	int i;
	int simple_q;

	i = 0;
	simple_q = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			simple_q++;
		i++;
	}
	return (simple_q == 0 ? -3 : -2);
}

int		odd_quote(char *quote, char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == *quote)
			count++;
		i++;
	}
	return (count % 2);
}
