/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_history_cmd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 10:43:11 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 13:36:39 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

#define HDATA shell->line_edit->history_data
#define HAS_HISTORY (HDATA && (hist = HDATA->heap))

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
		err_builtins(ERR_NO_HISTORY_AVAILABLE);
		return (0);
	}
	return (1);
}

int 			b_set_history_contain(char **args, t_shell *shell)
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
			if (hist->list[i] && ft_strstr(hist->list[i], query) &&
					!ft_strequ(hist->list[i], args[0]))
			{
				ft_copy_str(shell->line_edit->next_line,
				hist->list[i]);
				return (1);
			}
		}
		err_builtins(ERR_NO_HISTORY_THAT_CONTAIN, query);
		return (0);
	}
	else
	{
		err_builtins(ERR_NO_HISTORY_AVAILABLE);
		return (0);
	}
}

int 			b_set_history_start(char **args, t_shell *shell)
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
			if (hist->list[i] && ft_strstarts_with_str(hist->list[i], query) &&
				!ft_strequ(hist->list[i], args[0]))
			{
				ft_copy_str(shell->line_edit->next_line,
							hist->list[i]);
				return (1);
			}
		}
		err_builtins(ERR_NO_HISTORY_THAT_START, query);
		return (0);
	}
	else
	{
		err_builtins(ERR_NO_HISTORY_AVAILABLE);
		return (0);
	}
}

int 			b_set_history_from_n(char **args, t_shell *shell)
{
	int 	query;
	t_heap	*hist;

	query = ft_atoi((*args) + 1);
	if (HAS_HISTORY)
	{
		if (query < (int)hist->elements && hist->list[query])
		{
			ft_copy_str(shell->line_edit->next_line,
						hist->list[query]);
			return (1);
		}
		err_builtins(ERR_NO_HISTORY_FROM_BEGIN, query);
		return (0);
	}
	else
	{
		err_builtins(ERR_NO_HISTORY_AVAILABLE);
		return (0);
	}
}

int 			b_set_history_from_n_last(char **args, t_shell *shell)
{
	int 	query;
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
				ft_copy_str(shell->line_edit->next_line,
							hist->list[i]);
				return (1);
			}
		}
		err_builtins(ERR_NO_HISTORY_FROM_END, ft_atoi((*args) + 2));
		return (0);
	}
	else
	{
		err_builtins(ERR_NO_HISTORY_AVAILABLE);
		return (0);
	}
}

t_builtins_fun	*b_history_handler(char *cmd)
{
	if (ft_strequ(cmd, "!!"))
		return (b_set_last_history);
	if (ft_isalpha(cmd[1]))
		return (b_set_history_start);
	if (ft_isdigit(cmd[1]))
		return (b_set_history_from_n);
	if (cmd[1] == '-')
		return (b_set_history_from_n_last);
	if (ft_strstarts_with_str(cmd, "!?"))
		return (b_set_history_contain);
	return (NULL);
}