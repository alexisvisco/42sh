/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirect_to_functions.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 20:04:51 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 10:42:50 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

#define ISK(k) (k == c)

static redirect_fn	*ctrl_fn(char c)
{
	if (ISK(CTRL_T))
		return (ef_swap_char);
	if (ISK(CTRL_U))
		return (ef_delete_entire_line);
	if (ISK(CTRL_K))
		return (ef_delete_curr_to_end);
	if (ISK(CTRL_A))
		return (ef_go_home);
	if (ISK(CTRL_E))
		return (ef_go_home);
	if (ISK(CTRL_L))
		return (ef_clear_screen);
	if (ISK(CTRL_B))
		return (ef_move_left);
	if (ISK(CTRL_F))
		return (ef_move_right);
	if (ISK(CTRL_W))
		return (ef_del_prev_word);
	if (ISK(CTRL_I))
		return (ef_move_down);
	if (ISK(CTRL_O))
		return (ef_move_up);
	return (0);
}

static redirect_fn	*extra_fn(t_editor *l, char *seq)
{
	if ((seq[1] >= '0' && seq[1] <= '9') && read(l->ifd, seq + 2, 1) != -1)
	{
		if (seq[2] == '~' && seq[1] == '3')
			return (ef_del_simple);
		if (read(l->ifd, seq + 3, 1) == -1 || read(l->ifd, seq + 4, 1) == -1)
			return (NULL);
		else if (ft_strequ("[1;2A", seq))
			return (ef_move_up);
		else if (ft_strequ("[1;2B", seq))
			return (ef_move_down);
	}
	return (NULL);
}

static redirect_fn	*esc_fn(t_editor *l, char *seq)
{
	redirect_fn	*fn;

	if (read(l->ifd, seq, 1) == -1 || read(l->ifd, seq + 1, 1) == -1)
		return (NULL);
	if (seq[0] == '[')
	{
		if ((fn = extra_fn(l, seq)))
			return (fn);
		if (seq[1] == 'C')
			return (ef_move_right);
		if (seq[1] == 'D')
			return (ef_move_left);
		if (seq[1] == 'A')
			return (history_up);
		if (seq[1] == 'B')
			return (history_down);
		if (seq[1] == 'H')
			return (ef_go_home);
		if (seq[1] == 'F')
			return (ef_go_end);
	}
	else if (seq[0] == '0')
	{
		if (seq[1] == 'H')
			return (ef_go_home);
		if (seq[1] == 'F')
			return (ef_go_end);
	}
	return (0);
}

/*
** This function redirect keys entered to edit functions.
** An edit function take a (t_ediror *) in parameter and 
** return nothing.
*/

void			redirect_key_fn(t_editor *e, char c, char *seq, int nread)
{
	redirect_fn *func;
	
	if ((ISK(ESC) && (func = esc_fn(e, seq))) ||
		(func = ctrl_fn(c)) ||
		(ISK(BACKSPACE) && (func = ef_del_backspace)))
		func(e);
	else if (ft_isprint(c))
		editor_insert(e, c);
	refresh_line(e);
}
