/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_toks.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 14:16:18 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/17 11:26:33 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void		free_toks(t_token **tokens)
{
	int i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]->value);
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
