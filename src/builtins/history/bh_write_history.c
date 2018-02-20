/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bh_write_history.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 09:54:48 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:55:15 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Write the current history to the target file or default file
*/

int	write_history(char **args)
{
	char	path[2048];
	char	*file;
	int		ret;

	ft_copy_str(path, ht_get(g_shell.env, "HOME"));
	ft_strcat(path, "/"HISTORY_FILE);
	file = get_first_arg(args);
	ret = rewrite_history_file_in(HISTORY_DATA,
		file ? file :
		path, 0);
	if (ret)
	{
		message(MSG_HISTORY_WRITE, file ? file : path);
		return (1);
	}
	else
	{
		message_err(ERR_HISTORY_WRITE, file ? file : path);
		return (0);
	}
}
