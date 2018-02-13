/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   operator_error.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/28 14:03:09 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 15:39:40 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int			operator_error(t_block **blocks, t_token **tokens)
{
	int	nb_blocks;
	int	j;

	nb_blocks = 0;
	while ((*blocks)[nb_blocks].start_tok != -1)
		nb_blocks++;
	j = (*blocks)[nb_blocks - 1].end_tok;
	if (tokens[j]->value[0] == '|' || tokens[j]->value[0] == '&')
		return (-1);
	if (tokens[j + 1] && (tokens[j + 1]->value[0] == '|' ||
							tokens[j + 1]->value[0] == '&'))
		return (-1);
	return (0);
}
