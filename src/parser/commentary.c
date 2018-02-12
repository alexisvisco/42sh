/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   commentary.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/28 13:30:15 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 20:47:22 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Count the number of block until the comment block
*/

static int		count_block_until_com(t_token **tokens, int nb_tokens)
{
	int	i;
	int	block;

	i = 0;
	block = 0;
	while (i < nb_tokens)
	{
		while (tokens[i] && ft_strcmp(tokens[i]->value, "&") &&
		ft_strcmp(tokens[i]->value, "&&") && tokens[i]->value[0] != ';'
		&& ft_strcmp(tokens[i]->value, "&|"))
			i++;
		block++;
		if (tokens[i] && (ft_strcmp(tokens[i]->value, "&") == 0 ||
		ft_strcmp(tokens[i]->value, "&&") == 0 || tokens[i]->value[0] == ';' ||
		ft_strcmp(tokens[i]->value, "&|") == 0))
			i++;
	}
	return (block);
}

/*
** Check if it's a comment, a comment begin by a #
*/

int				is_commentary(t_token **tokens)
{
	int		i;

	i = 0;
	while (tokens[i])
	{
		if (tokens[i]->value[0] == '#')
			return (i);
		i++;
	}
	return (-1);
}

/*
** if there is a comment, extract all the block
*/

t_block			*extract_block_commentary(t_token **tokens, int nb_tokens)
{
	int		i;
	int		j;
	t_block	*blocks;
	int		begin;

	blocks = malloc(sizeof(t_block) *
	(count_block_until_com(tokens, nb_tokens) + 1));
	i = 0;
	j = 0;
	while (i < nb_tokens)
	{
		ft_bzero(&(blocks[j]), sizeof(t_block));
		begin = i;
		while (tokens[i]->value[0] != '&' && tokens[i]->value[0] != ';'
		&& tokens[i]->value[0] != '#')
			i++;
		blocks[j].start_tok = begin;
		blocks[j++].end_tok = i - 1;
		if (tokens[i] && (tokens[i]->value[0] == '&' ||
		tokens[i]->value[0] == ';' || tokens[i]->value[0] == '#'))
			i++;
	}
	blocks[j].start_tok = -1;
	return (blocks);
}
