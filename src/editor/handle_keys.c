/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_keys.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 10:50:17 by aviscogl     #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2018/02/08 10:27:27 by aviscogl    ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2018/02/07 14:46:31 by ggranjon    ###    #+. /#+    ###.fr     */
>>>>>>> bcce797a6d3cbc1d5cb3e70d1aca32a4fde881dd
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

static int		add_history(const t_editor *l)
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

	ft_bzero(seq, 10);
	while (42)
	{
		read(l->ifd, &c, 1);
		if (c == ENTER || c == '\n')
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
