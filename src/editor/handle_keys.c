/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_keys.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 10:47:39 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 22:25:50 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

int		handle_keys(t_editor *l)
{
	char	c;
	int		nread;
	char	seq[10];

	ft_bzero(seq, 10);
	while (42)
	{
		nread = read(l->ifd, &c, 1);
		if (c == ENTER)
		{
			ef_go_end(l);
			history_add(l);
			
			get_history(l)->index = -1;
			return ((int)l->len);
		}
		else
			redirect_key_fn(l, c, seq, nread);
	}
}
