/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   backquotes_parsing.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 14:28:33 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/20 14:13:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void		escape_useless_backquotes(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '`' && s[i + 1] && s[i + 1] == '`')
		{
			s[i] = ' ';
			s[i + 1] = ' ';
		}
		i++;
	}
}

static int	error_inception(t_token **u_tokens, t_block *u_blocks)
{
	free_toks(u_tokens);
	ft_memdel((void **)&u_blocks);
	message_err(ERR_INCE_BACK);
	return (-1);
}

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
		return (error_inception(u_tokens, u_blocks));
	if (parse_tokens(&u_tokens, (tokens[i]->value + 1), 1) < 0)
		return (-2);
	else if (parse_block(u_tokens, &u_blocks) < 0)
		return (-3);
	ret = core_exec_backquotes(u_tokens, u_blocks, tablea, &ret);
	ft_memdel((void **)&(tokens[i]->value));
	tokens[i]->value = ret.str;
	free_toks(u_tokens);
	ft_memdel((void **)&u_blocks);
	return (0);
}


static void		new_prompt(t_token **tokens)
{
	int		i;
	char 	*str;
	char 	*tmp;

	str = ft_strnew(1);
	i = 0;
	while (tokens[i])
	{
		if (tokens[i]->value)
		{
			tmp = str;
			str = ft_mine_strjoin(str, tokens[i]->value);
			free(tmp);
		}
		i++;
	}
	if (tokens)
		free_toks(tokens);
	ft_memdel((void **)&g_shell.line);
	g_shell.line = NULL;
	shell_process(str);
}

int			seek_backquotes(t_token **tokens)
{
	int		i;

	i = 0;
	while (tokens[i])
	{
		if (tokens[i]->value && tokens[i]->value[0] == '`')
		{
			if (parsing(tokens, i) < 0)
				return (-1);
			new_prompt(tokens);
			return (-2);
		}
		i++;
	}
	return (0);
}
