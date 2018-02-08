/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   history_search.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/03 21:41:01 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 19:26:49 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <shell.h>

static t_heap	*get_result(char *query, t_heap *h)
{
	t_heap *results;
	size_t i;

	results = heap_new(8);
	i = 0;
	while (i < h->size)
	{
		if (h->list[i])
			if (ft_strstarts_with_str(h->list[i], query) ||
				ft_strstr(h->list[i], query))
				heap_add(results, ft_strdup(h->list[i]));
		i++;
	}
	return (results);
}

static int		is_only_num(char *query)
{
	while (*query)
	{
		if (!ft_isdigit(*query))
			return (0);
		query++;
	}
	return (1);
}

static t_heap	*show_result(char *str, t_heap *history,
								t_heap *result)
{
	size_t i;

	i = 0;
	if (result)
		heap_free(result);
	result = get_result(str, history);
	while (i < result->elements)
	{
		if (result->list[i])
			ft_printf(" * %llu : %s\n", i, (char *)result->list[i]);
		i++;
	}
	free(str);
	return (result);
}

static int		update_line(t_editor *e, char *str, t_heap *result)
{
	char *tmp;

	if (result && is_only_num(str))
	{
		tmp = heap_get(result, (size_t)ft_atoi(str));
		if (tmp)
		{
			ef_delete_entire_line(e);
			editor_insert_str_without_refresh(e, tmp);
			heap_free(result);
			free(str);
			return (1);
		}
	}
	return (0);
}

/*
** Show history search prompt
** User need to type a text then a number to validate what history he want
*/

void			history_search(t_editor *e)
{
	char	*str;
	t_heap	*history;
	t_heap	*result;

	e->mode = HISTORY_SEARCH;
	history = e->options->history_data->heap;
	disable_terminal(0);
	result = NULL;
	history_search_msg();
	while ((str = readline("(search in history) ", g_shell.history_search)))
	{
		disable_terminal(0);
		if (ft_strequ("exit", str))
			break ;
		if (update_line(e, str, result))
			break ;
		result = show_result(str, history, result);
	}
	enable_terminal(0);
	e->mode = INSERTION;
	refresh_line(e);
}
