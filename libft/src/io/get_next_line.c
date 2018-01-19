/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/10 09:49:41 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/02 12:53:17 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		copyuntil(char **dst, char *src, char *er)
{
	int i;

	i = 0;
	while (src[i] != '\n' && src[i] != '\0')
		i++;
	if (!(*dst = ft_strnew(i)))
		return ((*er = 1));
	i = 0;
	while (src[i] != '\n' && src[i] != '\0')
	{
		(*dst)[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		return (i + 1);
	return (i);
}

static int		join_mem_buf(char **memorized, int fd, int *last, char *er)
{
	char	buf[BUFF_SIZE + 1];
	int		stream_size;
	char	*tmp;
	char	first_apple;

	first_apple = 0;
	while ((stream_size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		first_apple = 1;
		buf[stream_size] = '\0';
		if (!(tmp = ft_strjoin((!*memorized ? "" : *memorized + *last), buf)))
			return (*er = 1);
		*last = 0;
		if (*memorized)
			free(*memorized);
		*memorized = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (stream_size < 0)
		return (*er = 1);
	return (!first_apple && !ft_strlen((*memorized) + (*last)));
}

int				get_next_line(const int fd, char **line)
{
	static char		*memorized = NULL;
	static int		last = 0;
	char			eof;
	char			er;

	eof = 0;
	er = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	if (memorized && ft_strchr(memorized + last, '\n'))
	{
		last += copyuntil(line, memorized + last, &er);
		if (er)
			return (-1);
		return (1);
	}
	eof = join_mem_buf(&memorized, fd, &last, &er);
	if (er)
		return (-1);
	if (eof)
		return (0);
	last += copyuntil(line, memorized + last, &er);
	if (er)
		return (-1);
	return (1);
}
