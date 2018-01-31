/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_options.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 20:34:28 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 21:05:18 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
**
*/

void	set_options()
{
	t_options	*line_edit;

	line_edit = malloc(sizeof(t_options));
	line_edit->completion_data = NULL;
	line_edit->history_data = NULL;
	line_edit->has_history = 1;
	line_edit->has_completion = 1;
	g_shell.line_edit = line_edit;
}