/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bh_append_history.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 09:51:27 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:52:02 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Append the non writed history to the file or history file
*/

int	append_history(char **args)
{
	char	path[2048];
	char	*file;
	int		ret;

	if (!ht_has(g_shell.env, "HOME"))
		return (0);
	ft_copy_str(path, ht_get(g_shell.env, "HOME"));
	ft_strcat(path, "/"HISTORY_FILE);
	file = get_first_arg(args);
	ret = rewrite_history_file_in(HISTORY_DATA,
		file ? file :
		path, g_shell.line_edit->history_data->plus);
	if (ret)
	{
		message(MSG_HISTORY_APPENDED, file ? file : path);
		return (1);
	}
	else
	{
		message_err(ERR_HISTORY_APPENDED, file ? file : path);
		return (0);
	}
}
