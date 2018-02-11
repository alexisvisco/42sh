/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clear_used_before.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/25 12:56:58 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/11 17:29:50 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Clear all the lines used before. To do so start by
** going to the last row
*/

void	clear_used_before(t_refresher *r, t_buf *b)
{
	char *tmp;

	if (r->old_rows - r->rpos > 0)
	{
		tmp = ft_sprintf("\x1b[%dB", r->old_rows - r->rpos);
		buf_append(b, tmp, (int)ft_strlen(tmp));
		free(tmp);
	}
}
