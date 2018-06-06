/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   extract_backq.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 16:22:56 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 16:22:56 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		is_backq_in(t_token **tokens, int i)
{
	int	dquote;
	int	j;

	j = 0;
	dquote = 0;
	while (tokens[i]->value[j])
	{
		if (tokens[i]->value[j] == '\"')
			dquote++;
		else if (tokens[i]->value[j] == '\'' && dquote == 0)
			return (-1);
		if (tokens[i]->value[j] == '`')
			break ;
		j++;
	}
	if (tokens[i]->value[j] != '`')
		return (-1);
	return (j);
}

char	*extract_backq(t_token **tokens, int i, int start)
{
	int		k;
	char	*ret;

	ret = ft_strnew(ft_strlen(tokens[i]->value) - start + 1);
	k = start + 1;
	while (tokens[i]->value[k] && tokens[i]->value[k] != '`')
		k++;
	if (!(tokens[i]->value[k]))
	{
		message_err(ERR_BACKQUOTES);
		return (NULL);
	}
	ft_strncpy(ret, tokens[i]->value + start + 1, (size_t)k - start - 1);
	return (ret);
}
