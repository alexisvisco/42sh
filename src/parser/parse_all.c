/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_all.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/27 16:23:48 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 12:35:44 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void	change_variable(t_token ***tokens)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*tokens)[i])
	{
		if (ht_has(g_shell.env, (*tokens)[i]->value + 1))
		{
			tmp = ft_strrep_first_aft((*tokens)[i]->value, ht_get(g_shell.env,
				(*tokens)[i]->value + 1), (*tokens)[i]->value, 0);
			free((*tokens)[i]->value);
			(*tokens)[i]->value = tmp;
		}
		else if (ft_strrchr((*tokens)[i]->value, '~')
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
	change_variable(tokens);
	format_tokens_quotes(tokens);
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
