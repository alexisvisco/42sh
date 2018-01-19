/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editor.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 12:54:35 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/19 19:35:07 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

typedef struct termios t_termios

typedef struct	s_editor
{
	t_termios	origin;
	char		*buf;
	size_t		buf_len;
	const char	*prompt;
	size_t		plen;
	size_t		pos;
	size_t		len;
    size_t		cols;
    size_t		maxrows;
    int			history_index;
    t_mode		mode;
}				t_editor

#endif