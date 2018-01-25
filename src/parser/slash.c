/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   slash.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/25 14:24:49 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 17:26:11 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char			*remove_quotes(char *s)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		if ((s[i] == '\'' || s[i] == '\"') && s[i - 1] != '\\')
			i++;
		else
			new[j++] = s[i++];
	}
	return (new);
}

static void		quotes_help(char **new, int *i, int *j, char *s)
{
	int	k;

	k = 0;
	if (s[*i + 1] == 'a' && (k = 1))
		(*new)[(*j)++] = '\a';
	else if (s[*i + 1] == 'b' && (k = 1))
		(*new)[(*j)++] = '\b';
	else if (s[*i + 1] == 'f' && (k = 1))
		(*new)[(*j)++] = '\f';
	else if (s[*i + 1] == 'n' && (k = 1))
		(*new)[(*j)++] = '\n';
	else if (s[*i + 1] == 'r' && (k = 1))
		(*new)[(*j)++] = '\r';
	else if (s[*i + 1] == 't' && (k = 1))
		(*new)[(*j)++] = '\t';
	else if (s[*i + 1] == 'v' && (k = 1))
		(*new)[(*j)++] = '\v';
	else if (s[*i + 1] == '\\' && (k = 1))
		(*new)[(*j)++] = '\\';
	else
		(*new)[(*j)++] = s[(*i)];
	if (k == 1)
		(*i)++;
	(*i)++;
}

char			*change_quotes(char *s)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		if (s[i] == '\\')
			quotes_help(&new, &i, &j, s);
		else
			new[j++] = s[i++];
	}
	return (new);
}

void			format_tokens_quotes(t_token ***tokens)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*tokens)[i])
	{
		tmp = (*tokens)[i]->value;
		(*tokens)[i]->value = change_quotes((*tokens)[i]->value);
		free(tmp);
		tmp = (*tokens)[i]->value;
		(*tokens)[i]->value = remove_quotes((*tokens)[i]->value);
		free(tmp);
		i++;
	}
}
