/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   analyze.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 17:56:38 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:33:29 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*

int			analizered(t_block **blocks, t_token **tokens)
{
	int		i;

	i = 0;
	
}*/

void		isred(t_block **block, t_token **tokens)
{
	int		i;
	int		j;

	i = 0;
	while ((*block)[i].start_tok != -1)
	{
		j = (*block)[i].start_tok;
		(*block)[i].isredir = 0;
		while (j <= (*block)[i].end_tok)
		{
			if (tokens[j]->type == IO_REDIR || tokens[j]->type == SEP_OP)
			{
				if (ft_strchr(FT_REDIR, tokens[j]->value[0]) ||
					ft_strchr(FT_REDIR, tokens[j]->value[1]))
					(*block)[i].isredir = 1;
			}
			j++;
		}
		i++;
	}
}

void		analizeblock(t_block **blocks, t_token **tokens)
{
	isred(blocks, tokens);
}
