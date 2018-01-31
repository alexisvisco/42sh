/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_keys.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 10:47:39 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 20:20:32 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Handle the first key entered then redirect it to redirect_key_fn(..)
** If the key pressed is ENTER finish return the len of the buffer
*/

int		handle_keys(t_editor *l)
{
	char	c;
	char	seq[10];

	ft_bzero(seq, 10);
	while (42)
	{
		read(l->ifd, &c, 1);
		if (c == ENTER || c == '\n')
		{
			ef_go_end(l);
			if (l->options->has_history)
			{
				if (ft_strlen(l->buf) > 0)
					history_add(l);
				l->options->history_data->index = -1;
			}
			return ((int)l->len);
		}
		else
			redirect_key_fn(l, c, seq);
	}
}
