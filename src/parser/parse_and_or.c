/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_and_or.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 17:09:33 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 13:26:21 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	analyze_or_and(t_block **block, t_token **tokens)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while ((*block)[i].start_tok != -1)
	{
		j = (*block)[i].start_tok;
		while (j <= (*block)[i].end_tok)
		{
			if (ft_strequ(tokens[j]->value, "&&"))
				(*block)[i].my_op[k++] = TY_AND;
			else if (ft_strequ(tokens[j]->value, "||"))
				(*block)[i].my_op[k++] = TY_OR;
			j++;
		}
		i++;
	}
}
