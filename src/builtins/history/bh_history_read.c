/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bh_history_read.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 09:53:57 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:54:19 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void		end(const char *path, const char *file)
{
	rewrite_history_file(HISTORY_DATA);
	free_gnl();
	message(MSG_HISTORY_READ, file ? file : path);
}

/*
** Read entirely the file and reset the history heap
*/

int				history_read(char **args)
{
	char	path[2048];
	char	*file;
	char	*line;
	int		fd;

	if (!ht_get(g_shell.env, "HOME"))
		return (0);
	ft_copy_str(path, ht_get(g_shell.env, "HOME"));
	ft_strcat(path, "/"HISTORY_FILE);
	file = get_first_arg(args);
	if ((fd = open(file ? file : path, O_CREAT | O_RDONLY)) < 0)
	{
		message_err(ERR_HISTORY_READ, file ? file : path);
		return (0);
	}
	heap_free(HISTORY_DATA);
	HISTORY_DATA = heap_new(32);
	while (get_next_line(fd, &line))
	{
		heap_add(HISTORY_DATA, ft_strdup(line));
		ft_memdel((void **)&line);
	}
	end(path, file);
	return (1);
}
