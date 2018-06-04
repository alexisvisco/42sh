/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/10 09:49:41 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		list_add(t_gnl **save, t_gnl *elem)
{
	t_gnl *list;

	list = *save;
	while (list->next != NULL)
		list = list->next;
	list->next = elem;
}

static t_gnl	*new_list(int fd)
{
	t_gnl *list;

	if (!(list = (t_gnl*)ft_memalloc(sizeof(*list))))
		return (NULL);
	list->fd = fd;
	list->tempo = ft_strnew(0);
	list->text = NULL;
	list->next = NULL;
	return (list);
}

static t_gnl	*check_fd(t_gnl *save, int fd)
{
	t_gnl *tmp;
	t_gnl *d_list;

	d_list = save;
	while (d_list)
	{
		if (d_list->fd == fd)
			return (d_list);
		if (!(d_list->next))
		{
			tmp = new_list(fd);
			list_add(&d_list, tmp);
			return (tmp);
		}
		d_list = d_list->next;
	}
	return (NULL);
}

static int		check(char *save, char **line)
{
	char	*fin;

	if (!save)
		return (0);
	fin = ft_strchr(save, '\n');
	if (fin != NULL)
	{
		*fin = '\0';
		*line = ft_strdup(save);
		ft_strncpy(save, &fin[1], ft_strlen(&fin[1]) + 1);
		return (1);
	}
	else if (ft_strlen(save) > 0)
	{
		*line = ft_strdup(save);
		*save = '\0';
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_gnl	**save;
	t_gnl			*tmp;
	int				ret;

	save = get_gnl();
	if (!(*save))
		*save = new_list(fd);
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (-1);
	tmp = check_fd(*save, fd);
	while (!(ft_strchr(tmp->tempo, '\n')))
	{
		ret = (int)read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (check(tmp->text, line));
		buf[ret] = '\0';
		tmp->text = ft_strjoin(tmp->tempo, buf);
		ft_memdel((void **)&(tmp->tempo));
		tmp->tempo = tmp->text;
	}
	return (check(tmp->text, line));
}
