/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bad_format_sep.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 10:31:30 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 17:06:33 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int			analyze_sep(t_token **tokens)
{
	int i;

	i = 0;
	if (tokens[0])
	{
		if (tokens[0]->type == IO_REDIR || tokens[0]->type == SEP_OP)
		{
			message_err(ERR_SYNTAX_NEAR_TOKEN, tokens[0]->value);
			return (-2);
		}
	}
	while (tokens[i + 1])
	{
		if (tokens[i]->type == SEP_OP && tokens[i + 1]->type == SEP_OP)
		{
			message_err(ERR_SYNTAX_NEAR_TOKEN, tokens[i]->value);
			return (-1);
		}
		i++;
	}
	return (0);
}
