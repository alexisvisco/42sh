/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bh_history_non_read.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 09:52:22 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:53:07 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Read the line non read of the history file
*/

int	history_non_read(void)
{
	char	path[2048];
	char	*line;
	int		i;
	int		fd;

	ft_copy_str(path, ht_get(g_shell.env, "HOME"));
	ft_strcat(path, "/"HISTORY_FILE);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		message_err(ERR_HISTORY_NON_READ);
		return (0);
	}
	i = 0;
	while (get_next_line(fd, &line))
	{
		if (i >= g_shell.line_edit->history_data->plus)
			heap_add(HISTORY_DATA, ft_strdup(line));
		free(line);
		i++;
	}
	free_gnl();
	message(MSG_HISTORY_NON_READ);
	return (1);
}
