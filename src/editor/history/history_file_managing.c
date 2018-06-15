/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   history_file_managing.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/17 09:58:05 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 10:12:38 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	get_previous_history(t_heap *hist)
{
	char	path[2048];
	char	*line;
	int		fd;
	int		i;

	i = 0;
	if (!ht_has(g_shell.env, "HOME"))
		return ;
	ft_copy_str(path, ht_get(g_shell.env, "HOME"));
	ft_strcat(path, "/"HISTORY_FILE);
	if (access(path, F_OK) == -1)
		return ;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		i++;
		heap_add(hist, ft_strdup(line));
		ft_memdel((void **)&line);
	}
	g_shell.line_edit->history_data->plus = i;
	close(fd);
	free_gnl();
}

int		rewrite_history_file(t_heap *h)
{
	char	path[2048];
	int		fd;
	size_t	i;

	if (!ht_has(g_shell.env, "HOME"))
		return (0);
	ft_copy_str(path, ht_get(g_shell.env, "HOME"));
	ft_strcat(path, "/"HISTORY_FILE);
	fd = open(path, O_CREAT | O_WRONLY | O_TRUNC,
	S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	i = 0;
	if (fd < 0)
		return (0);
	while (i < h->size)
	{
		if (h->list[i])
			ft_dprintf(fd, "%s\n", h->list[i]);
		i++;
	}
	close(fd);
	return (1);
}

int		rewrite_history_file_in(t_heap *h, const char *path, int from)
{
	int		fd;
	size_t	i;

	fd = open(path, O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	i = from + (size_t)1;
	if (fd < 0)
		return (0);
	while (i < h->size)
	{
		if (h->list[i])
			ft_dprintf(fd, "%s\n", h->list[i]);
		i++;
	}
	close(fd);
	return (1);
}
