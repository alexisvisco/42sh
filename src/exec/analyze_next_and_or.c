/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   analyze_next_and_or.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 19:01:40 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 12:34:46 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int			analyze_next_and_or(char *s)
{
	if (ft_strequ(s, "&&"))
		return (3);
	if (ft_strequ(s, "||"))
		return (4);
	return (0);
}

int			go_to_next(t_token **tokens, t_block *block, int num, int index)
{
	if (ft_strequ(tokens[index]->value, "&&") ||
		ft_strequ(tokens[index]->value, "||"))
		index++;
	while (index < block[num].end_tok)
	{
		if (ft_strequ(tokens[index]->value, "&&") ||
		ft_strequ(tokens[index]->value, "||"))
			return (index - 1);
		index++;
	}
	return (block[num].end_tok);
}
