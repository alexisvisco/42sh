/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heredoc.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 17:53:32 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 12:08:01 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int		open_heredoc(char *str)
{
	int	file;

	file = open("/tmp/.heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*str)
		write(file, str, ft_strlen(str));
	close(file);
	file = open("/tmp/.heredoc", O_RDONLY);
	free(str);
	return (file);
}

static t_heap	*ask_line_heredoc(char *prompt,
				int (*is_end)(const char *cmp, const char *line), char *cmp)
{
	char		*line;
	t_heap		*result;
	t_options	options;

	options.history_data = NULL;
	options.completion_data = NULL;
	options.has_completion = 1;
	options.has_history = 0;
	result = heap_new(4);
	while ((line = readline(prompt, &options)))
	{
		if ((is_end && is_end(cmp, line)))
		{
			free(line);
			break ;
		}
		else
			heap_add(result, ft_strjoin(line, "\n"));
		free(line);
	}
	free_e_content(options.completion_data);
	free_e_content(options.history_data);
	return (result);
}

static char		*heap_to_str_here(t_heap *h)
{
	char		*full;
	char		*tmp;
	size_t		i;

	i = 0;
	full = ft_strdup("\0");
	while (i < h->size)
	{
		if (h->list[i])
		{
			tmp = full;
			full = ft_strjoin(full, h->list[i]);
			free(tmp);
		}
		i++;
	}
	heap_free(h);
	return (full);
}

static char		*prompt_heredoc(char *str)
{
	return (heap_to_str_here(ask_line_heredoc("heredoc> ", ft_strequ, str)));
}

int				call_heredoc(char ***cmds, int fd2)
{
	int	k;
	int	fd;

	k = 0;
	while ((*cmds)[k])
	{
		if (ft_strequ((*cmds)[k], "<<"))
			break ;
		k++;
	}
	if ((*cmds)[k] == NULL || fd2 > 0)
		return (fd2);
	if ((*cmds)[k + 1] == NULL)
		return (-1);
	fd = open_heredoc(prompt_heredoc((*cmds)[k + 1]));
	tab_del_from_to(cmds, k, k + 1);
	return (fd);
}
