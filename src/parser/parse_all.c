/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_all.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/27 16:23:48 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 18:10:34 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void	replace_placeholder(t_token ***tokens)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*tokens)[i])
	{
		if (ft_strrchr((*tokens)[i]->value, '~')
			&& ht_has(g_shell.env, "HOME"))
		{
			tmp = ft_strrep_first_aft("~", ht_get(g_shell.env, "HOME"),
				(*tokens)[i]->value, 0);
			free((*tokens)[i]->value);
			(*tokens)[i]->value = tmp;
		}
		i++;
	}
}

int			parse_tokens(t_token ***tokens, char *s)
{
	if (lex_all(tokens, s) < 0)
		return (-1);
	if (analyze_sep(*tokens) < 0)
		return (-2);
	replace_placeholder(tokens);
	format_tokens_quotes(tokens);
	if (seek_backquotes(*tokens) < 0)
		return (-3);
	return (1);
}

int			parse_block(t_token **tokens, t_block **blocks)
{
	int	i;

	if ((i = is_commentary(tokens)) == -1)
		*blocks = extract_blocks(tokens);
	else if (i == 0)
	{
		message_err(ERR_ONLY_COMMENT, NULL);
		return (-2);
	}
	else
		*blocks = extract_block_commentary(tokens, i);
	if (operator_error(blocks, tokens) == -1)
	{
		message_err(ERR_BAD_END, NULL);
		return (-3);
	}
	if (analyze_block(blocks, tokens) == -2)
		return (-1);
	extract_type_redir(tokens, blocks);
	return (1);
}
