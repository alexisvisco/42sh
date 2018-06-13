/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_key_control.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/28 12:59:58 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/28 12:59:58 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

#define ISK(k) (k == c)

int	redirect_control_key(t_editor *e, char c)
{
	if (ISK(CTRL_C))
	{
		ef_go_end(e);
		refresh_line(e);
		ft_putchar('\n');
		e->buf[0] = 0;
		init_editor(e, e->buf, e->prompt, e->options);
		refresh_line(e);
		return (1);
	}
	if (ISK(TAB) && e->options->has_completion)
	{
		completion_handler(e);
		return (1);
	}
	if (ISK(CTRL_V))
	{
		ef_paste_clipboard(e);
		return (1);
	}
	return (0);
}
