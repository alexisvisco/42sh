/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   backquotes_parsing.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 14:28:33 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 20:12:41 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	parsing(t_token **tokens, int i)
{
	t_token			**u_tokens;
	t_block			*u_blocks;
	int				tablea[2];
	t_backquotes	ret;

	tablea[0] = 0;
	tablea[1] = 0;
	u_tokens = NULL;
	u_blocks = NULL;
	ret.status = 0;
	ret.str = ft_strnew(1);
	if (tokens[i]->value[ft_strlen(tokens[i]->value) - 1] == '`')
		tokens[i]->value[ft_strlen(tokens[i]->value) - 1] = '\0';
	else
		return (-1);
	if (parse_tokens(&u_tokens, (tokens[i]->value + 1)) < 0)
		return (-2);
	else if (parse_block(u_tokens, &u_blocks) < 0)
		return (-3);
	ret = core_exec_backquotes(u_tokens, u_blocks, tablea, &ret);
	free(tokens[i]->value);
	tokens[i]->value = ret.str;
	free_toks(u_tokens);
	free(u_blocks);
	return (0);
}

int			seek_backquotes(t_token **tokens)
{
	int		i;

	i = 0;
	while (tokens[i])
	{
		if (tokens[i]->value && tokens[i]->value[0] == '`')
			if (parsing(tokens, i) < 0)
				return (-1);
		i++;
	}
	return (0);
}
