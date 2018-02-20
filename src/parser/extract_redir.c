/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   extract_redir.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/25 11:53:40 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:32:25 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void			extract_type_redir(t_token **tokens, t_block **block)
{
	int		i;
	int		j;

	i = 0;
	while ((*block)[i].start_tok != -1)
	{
		j = (*block)[i].start_tok;
		while (j <= (*block)[i].end_tok)
		{
			if (tokens[j]->type == IO_REDIR)
			{
				if (ft_strcmp("<<", tokens[j]->value) == 0)
					(*block)[i].isredir[1] = 1;
				else if (ft_strcmp("<", tokens[j]->value) == 0)
					(*block)[i].isredir[1] = 2;
				else if (ft_strcmp(">", tokens[j]->value) == 0)
					(*block)[i].isredir[1] = 3;
				else if (ft_strcmp(">>", tokens[j]->value) == 0)
					(*block)[i].isredir[1] = 4;
			}
			j++;
		}
		i++;
	}
}
