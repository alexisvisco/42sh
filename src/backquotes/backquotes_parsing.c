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

static char	*my_str_rep(char *search, char *replace, char *subject, int n)
{
	char	*ret;
	char	*tmp;

	if (!search || !replace || !subject || !(ft_strstr(subject, search)))
		return (NULL);
	ret = ft_strnew(ft_strlen(subject) - n + ft_strlen(replace) + 1);
	ft_strncpy(ret, subject, n);
	tmp = ret;
	ret = ft_strjoin(ret, replace);
	free(tmp);
	tmp = ret;
	ret = ft_strjoin(ret, subject + ft_strlen(search) + n + 2);
	free(tmp);
	return (ret);
}

static int	return_and_free(t_token **tokens, t_block **blocks, int ret)
{
	if (tokens)
		free_toks(tokens);
	if (blocks)
		ft_memdel((void **)blocks);
	return (ret);
}

static int	parsing(t_token **tokens, char **str, int i, int start)
{
	t_token			**u_tokens;
	t_block			*u_blocks;
	int				tablea[2];
	t_backquotes	ret;
	char			*tmp;

	tablea[0] = 0;
	tablea[1] = 0;
	u_tokens = NULL;
	u_blocks = NULL;
	ft_bzero(&ret, sizeof(t_backquotes));
	if (parse_tokens(&u_tokens, *str, 1) < 0)
		return (return_and_free(u_tokens, &u_blocks, -2));
	else if (parse_block(u_tokens, &u_blocks) < 0)
		return (return_and_free(u_tokens, &u_blocks, -3));
	ret = core_exec_backquotes(u_tokens, u_blocks, tablea, &ret);
	tmp = tokens[i]->value;
	tokens[i]->value = my_str_rep(*str, ret.str, tokens[i]->value, start);
	free_toks(u_tokens);
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&ret.str);
	ft_memdel((void **)&u_blocks);
	ft_memdel((void**)str);
	return (0);
}

static void	new_prompt(t_token **tokens)
{
	int		i;
	char	*str;
	char	*tmp;

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
	shell_process(str, 1);
}

int			seek_backquotes(t_token **tokens)
{
	int		i;
	int		start;
	char	*str;

	i = 0;
	while (tokens[i])
	{
		if (tokens[i]->value)
		{
			if ((start = is_backq_in(tokens, i)) >= 0)
			{
				if ((str = extract_backq(tokens, i, start)))
				{
					if (parsing(tokens, &str, i, start) < 0)
						return (-1);
					new_prompt(tokens);
					return (-2);
				}
			}
		}
		i++;
	}
	return (0);
}
