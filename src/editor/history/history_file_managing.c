/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_history.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/17 09:58:05 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/17 11:26:34 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void get_previous_history(t_heap *hist)
{
	char path[2048];
	char *line;
	int fd;

	ft_copy_str(path, ht_get(g_shell.env, "HOME"));
	ft_strcat(path, "/"HISTORY_FILE);
	if (access(path, F_OK) == -1)
		return;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		heap_add(hist, ft_strdup(line));
		free(line);
	}
	close(fd);
	free_gnl();
}

void rewrite_history_file(t_heap *h)
{
	char path[2048];
	int fd;
	size_t i;

	ft_copy_str(path, ht_get(g_shell.env, "HOME"));
	ft_strcat(path, "/"HISTORY_FILE);
	fd = open(path, O_APPEND | O_CREAT | O_WRONLY,
	S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	i = 0;
	while (i < h->size)
	{
		if (h->list[i])
			ft_dprintf(fd, "%s\n", h->list[i]);
		i++;
	}
	close(fd);
}
