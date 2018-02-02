/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_all.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/27 16:23:48 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 17:47:35 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		parse_tokens(t_token ***tokens, char *s)
{
	if (ft_lexall(tokens, s) == -2)
		return (-1);
	format_tokens_quotes(tokens);
	return (1);
}

int		parse_block(t_token **tokens, t_block **blocks)
{
	int	i;

	if ((i = is_commentary(tokens)) == -1)
		*blocks = extract_blocks(tokens);
	else if (i == 0)
	{
		e_parse(ERR_ONLY_COMMENT, NULL);
		return (-2);
	}
	else
		*blocks = extract_block_commentary(tokens, i);
	if (operator_error(blocks, tokens) == -1)
	{
		e_parse(ERR_BAD_END, NULL);
		return (-3);
	}
	if (analyze_block(blocks, tokens) == -2)
		return (-1);
	extract_type_redir(tokens, blocks);
	return (1);
}
