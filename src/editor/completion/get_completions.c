/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_completions.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 10:01:06 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 11:26:27 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	get_completions(t_editor *e)
{
	t_word_info	info;

	set_word_info(&info, e);
	if (info.type == TYPE_COMMAND_OR_BIN)
	{
		get_completions_bin(&info, e->options->completion_data->heap);
		get_completions_path(&info, e->options->completion_data->heap);
	}
	else
		get_completions_env(&info, e->options->completion_data->heap);
	if (e->options->completion_data->origin[0] == '\0')
		ft_copy_str(e->options->completion_data->origin, info.current_word);
	free(info.current_word);
}
