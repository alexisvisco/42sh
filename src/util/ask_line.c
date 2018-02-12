/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ask_line.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 13:56:50 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 15:08:49 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_heap		*ask_line(char *prompt, int enable_completion,
					int (*is_end)(char *cmp, char *line), char *cmp)
{
	char		*line;
	t_heap		*result;
	t_options	options;

	options.history_data = NULL;
	options.completion_data = NULL;
	options.has_completion = enable_completion;
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
			heap_add(result, ft_strjoin(line, "\n"));
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
