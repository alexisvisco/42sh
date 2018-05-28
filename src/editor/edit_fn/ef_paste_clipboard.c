/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ef_clear_screen.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 20:31:56 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Insert text from clipboard
*/

void	 ef_paste_clipboard(t_editor *l)
{
	const char	*t[] = {"/usr/bin/pbpaste", NULL};
	char			*clipboard;

	clipboard = exec_to_str(t);
	editor_insert_str(l, clipboard);
	free(clipboard);
	refresh_line(l);
}
