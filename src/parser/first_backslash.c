/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   first_backslash.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/07 10:44:01 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 10:44:01 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char	*change_first_backquotes(char *s)
{
	char	*new;
	int 	in_quote;
	int		i;
	int		j;

	i = 0;
	in_quote = 0;
	j = 0;
	new = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"' || s[i] == '`')
			in_quote = 1;
		if (in_quote == 0 && s[i] == '\\')
		{
			if (s[i + 1] >= ' ' && s[i + 1] <= '~' && s[i + 1] >= '\''
			&& s[i + 1] >= '\"' && s[i + 1] >= '`')
				i++;
		}
		else
			new[j++] = s[i++];
	}
	return (new);
}

char		*change_back_quotes(char *s)
{
	char	*new;
	int		i;
	int		k;
	int		j;

	i = 0;
	j = 0;
	new = ft_strnew(ft_strlen(s));
	while (s[i] && (k = 0) == 0)
	{
		if (s[i] == '\\')
		{
			if (s[i + 1] == '\'' && (k = 1))
				new[j++] = '\'';
			else if (s[i + 1] == '\"' && (k = 1))
				new[j++] = '\"';
			else
				new[j++] = s[i];
			i = (k == 1) ? i + 2 : i + 1;
		}
		else
			new[j++] = s[i++];
	}
	return (new);
}
