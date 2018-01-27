/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_all.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/27 16:23:48 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/27 17:14:22 by ggranjon    ###    #+. /#+    ###.fr     */
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
	*blocks = extractblock(tokens);
	if (analyze_block(blocks, tokens) == -2)
		return (-1);
	extract_type_redir(tokens, blocks);
	return (1);
}
