/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_history_func.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 10:40:59 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 11:13:55 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

#define HDATA shell->line_edit->history_data
#define HAS_HISTORY (HDATA && (hist = HDATA->heap))
#define CONTAIN hist->list[i] && ft_strstr(hist->list[i], query)
#define START hist->list[i] && ft_strstarts_with_str(hist->list[i], query)

/*
** !! : set the next buffer line to the last command typed
*/

int				b_set_last_history(char **args, t_shell *shell)
{
	t_heap *hist;

	(void)args;
	if (HAS_HISTORY)
	{
		if (hist->elements > 1)
		{
			ft_copy_str(shell->line_edit->next_line,
						hist->list[hist->elements - 2]);
		}
	}
	else
	{
		message_err(ERR_NO_HISTORY_AVAILABLE);
		return (0);
	}
	return (1);
}

/*
** !?name : set the next buffer line to the last command that contain 'name'
*/

int				b_set_history_contain(char **args, t_shell *shell)
{
	char	*query;
	t_heap	*hist;
	size_t	i;

	query = (*args) + 2;
	if (query && *query && HAS_HISTORY)
	{
		i = hist->elements + 1;
		while (--i <= hist->elements)
		{
			if (CONTAIN && !ft_strequ(hist->list[i], args[0]))
			{
				ft_copy_str(shell->line_edit->next_line, hist->list[i]);
				return (1);
			}
		}
		message_err(ERR_NO_HISTORY_THAT_CONTAIN, query);
		return (0);
	}
	else
	{
		message_err(ERR_NO_HISTORY_AVAILABLE);
		return (0);
	}
}

/*
** !name : set the next buffer line to the last command that start with 'name'
*/

int				b_set_history_start(char **args, t_shell *shell)
{
	char	*query;
	t_heap	*hist;
	size_t	i;

	query = (*args) + 1;
	if (query && *query && HAS_HISTORY)
	{
		i = hist->elements + 1;
		while (--i <= hist->elements)
		{
			if (START && !ft_strequ(hist->list[i], args[0]))
			{
				ft_copy_str(shell->line_edit->next_line, hist->list[i]);
				return (1);
			}
		}
		message_err(ERR_NO_HISTORY_THAT_START, query);
		return (0);
	}
	else
	{
		message_err(ERR_NO_HISTORY_AVAILABLE);
		return (0);
	}
}

/*
** !n : set the next buffer line to the n history index from begin
*/

int				b_set_history_from_n(char **args, t_shell *shell)
{
	int		query;
	t_heap	*hist;

	query = ft_atoi((*args) + 1);
	if (HAS_HISTORY)
	{
		if (query < (int)hist->elements && hist->list[query])
		{
			ft_copy_str(shell->line_edit->next_line, hist->list[query]);
			return (1);
		}
		message_err(ERR_NO_HISTORY_FROM_BEGIN, query);
		return (0);
	}
	else
	{
		message_err(ERR_NO_HISTORY_AVAILABLE);
		return (0);
	}
}

/*
** !-n : set the next buffer line to the n history index from end
*/

int				b_set_history_from_n_last(char **args, t_shell *shell)
{
	int		query;
	t_heap	*hist;
	size_t	i;
	int		j;

	if ((query = (ft_atoi((*args) + 2)) + 1) && HAS_HISTORY)
	{
		i = hist->elements;
		j = -1;
		while (--i <= hist->elements)
		{
			if (++j == query && hist->list[i])
			{
				ft_copy_str(shell->line_edit->next_line, hist->list[i]);
				return (1);
			}
		}
		message_err(ERR_NO_HISTORY_FROM_END, ft_atoi((*args) + 2));
		return (0);
	}
	else
	{
		message_err(ERR_NO_HISTORY_AVAILABLE);
		return (0);
	}
}
