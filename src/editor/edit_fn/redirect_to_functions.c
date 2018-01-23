/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirect_to_functions.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 20:04:51 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 20:56:41 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

#define ISK(k) (k == c)

redirect_fn *ctrl_fn(char c)
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
}

void	redirect_key_fn(t_editor *e, char c, char *seq, int nread)
{
	
}