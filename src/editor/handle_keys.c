/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_keys.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 15:40:09 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 15:39:43 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <builtins.h>
#include "editor.h"

static int		add_history(t_editor *l)
{
	if (l->options->has_history)
	{
		if (ft_strlen(l->buf) > 0)
			history_add(l);
		l->options->history_data->index = -1;
	}
	return ((int)l->len);
}

/*
** Handle the first key entered then redirect it to redirect_key_fn(..)
** If the key pressed is ENTER finish return the len of the buffer
*/

int				handle_keys(t_editor *l)
{
	char	c;
	char	seq[10];
	int		enter;

	ft_bzero(seq, 10);
	enter = 0;
	while (42)
	{
		read(l->ifd, &c, 1);
		if (c == CTRL_D && ft_strequ(l->buf, "") && (enter = 1))
			ft_copy_str(l->buf, "exit");
		if (enter || c == ENTER || c == '\n')
		{
			if (l->mode == COMPLETION)
			{
				completion_delete(l);
				continue ;
			}
			ef_go_end(l);
			return (add_history(l));
		}
		else
			redirect_key_fn(l, c, seq);
	}
}
