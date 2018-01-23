/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   block.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 14:07:56 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 15:52:55 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	countsep(t_token **tokens)
{
	int	i;
	int	block;

		ft_printf("\nICI %s\n", tokens[0]->value);
	i = 0;
	block = 0;
	while (tokens[i])
	{
		printf("%i test\n", i);
		while (tokens[i] && !(ft_strchr(SPLITCMD, tokens[i]->value[0])))
			i++;
		block++;
		i++;
	}
	return (block);
}

t_block		*extractblock(t_token **tokens)
{
	int		i;
	int		j;
	t_block	*blocks;
	int		begin;

	blocks = malloc(sizeof(t_block) * (countsep(tokens) + 1));
	i = 0;
	j = 0;
	while (tokens[i])
	{
		begin = i;
		while (tokens[i] &&
			(tokens[i]->value[0] != '&' || tokens[i]->value[0] != ';'))
			i++;
		blocks[j].start_tok = begin;
		blocks[j++].end_tok = i;
		i++;
	}
	blocks[j].start_tok = -1;
	blocks[j].end_tok = -1;
	return (blocks);
}