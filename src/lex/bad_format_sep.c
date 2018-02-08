/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bad_format_semicolon.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 10:31:30 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 11:13:51 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int			analyze_sep(t_token **tokens)
{
	int i;

	i = 0;
	if (tokens[0]->value)
	{
		if (tokens[0]->value[0] == ';')
		{
			message_err(ERR_SEMICOL, tokens[i]->value);
			return (-2);
		}
	}
	while (tokens[i + 1])
	{
		if (tokens[i]->type == SEP_OP && tokens[i + 1]->type == SEP_OP)
		{
			message_err(ERR_SEMICOL, tokens[i]->value);
			return (-1);
		}
		i++;
	}
	return (0);
}
