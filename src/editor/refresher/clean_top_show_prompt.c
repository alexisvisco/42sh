/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clean_top_show_prompt.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/25 12:56:58 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 14:15:42 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Clean the top line
** Write the prompt and the current buffer content
*/

void	clean_top_show_prompt(t_editor *e, t_buf *b)
{
	const char	*s = "\r\x1b[0K";
	const int	len = 6;

	buf_append(b, s, len);
	buf_append(b, e->prompt, (int)e->plen);
	buf_append(b, e->buf, (int)e->len);
}
