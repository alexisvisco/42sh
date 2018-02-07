/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_options.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 20:34:28 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 14:46:31 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Set options for line editing
*/

void	set_options()
{
	t_options	*line_edit;
	t_options	*history_search;

	line_edit = malloc(sizeof(t_options));
	line_edit->completion_data = NULL;
	line_edit->history_data = NULL;
	line_edit->has_history = 1;
	line_edit->has_completion = 1;
	line_edit->next_line[0] = 0;
	history_search = malloc(sizeof(t_options));
	history_search->completion_data = NULL;
	history_search->history_data = NULL;
	history_search->has_history = 1;
	history_search->has_completion = 1;
	history_search->next_line[0] = 0;
	g_shell.history_search = history_search;
	g_shell.line_edit = line_edit;
}