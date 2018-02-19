/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ask_line.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 13:56:50 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 13:26:21 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_heap		*ask_line(char *prompt, int nl,
					int (*is_end)(char *cmp, char *line), char *cmp)
{
	char		*line;
	t_heap		*result;
	t_options	options;

	options.history_data = NULL;
	options.completion_data = NULL;
	options.has_completion = 1;
	options.has_history = 1;
	result = heap_new(4);
	while ((line = readline(prompt, &options)))
	{
		if ((is_end && is_end(cmp, line)))
		{
			heap_add(result, ft_strdup(line));
			free(line);
			break ;
		}
		else
			heap_add(result, nl ? ft_strjoin(line, "\n") : ft_strdup(line));
		free(line);
	}
	free_e_content(options.completion_data);
	free_e_content(options.history_data);
	return (result);
}

char		*heap_to_str(t_heap *h)
{
	char		*full;
	char		*tmp;
	size_t		i;

	i = 0;
	full = ft_strdup("\n");
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

char		*heap_to_str_rm_one(t_heap *h)
{
	char		*tmp;
	char		*full;
	size_t		i;

	i = 0;
	full = ft_strdup("\0");
	while (i < h->size)
	{
		if (h->list[i])
		{
			tmp = full;
			full = ft_strjoin(full, h->list[i]);
			if (ft_strends_with(full, '\\'))
				full[ft_strlen(full) - 1] = 0;
			free(tmp);
		}
		i++;
	}
	heap_free(h);
	return (full);
}
