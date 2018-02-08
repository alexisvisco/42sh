/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   count_tokens.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/28 14:28:00 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 12:22:55 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
**	if  -2 is returned : quotes problem
*/

int				count_tokens(char *s)
{
	char	*word;
	int		nbword;

	nbword = 0;
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s)
		{
			word = specpy(s);
			nbword++;
			if (!word)
				return (-2);
			s += nb_equal_char(s, word);
			ft_strdel(&word);
		}
	}
	return (nbword);
}

int				nb_equal_char(char *s1, char *s2)
{
	int		ret;

	ret = 0;
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		ret++;
	}
	return (ret);
}
