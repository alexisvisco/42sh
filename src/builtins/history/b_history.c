/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_history.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 15:41:57 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int 		grp_contain(int i, int x, const char **grp, char *ar)
{
	return ((ft_contain_any_seq(ar, grp[i])) ||
	(ft_contain_any_seq(ar, grp[x])));
}

/*
** Check compatibility betweens each arguments
*/

static int		check_errors(char *ar)
{
	const char	*grp[] = {"d", "e", "canwr"};
	int			i;

	i = -1;
	while (ar[++i])
	{
		if ((ft_strchr(grp[0], *ar) && grp_contain(1, 2, grp, ar)) ||
			(ft_strchr(grp[1], *ar) && grp_contain(0, 2, grp, ar)) ||
			(ft_strchr(grp[2], *ar) && grp_contain(0, 1, grp, ar)))
		{
			message_err(ERR_HISTORY_ARG_MERGED);
			return (1);
		}
	}
	return (0);
}

/*
** Redistribute with arguments
*/

static int		exec_arguments(char *ar, char **args)
{
	if (*ar)
	{
		while (*ar)
		{
			if (*ar == 'c' && !clear_history())
				return (0);
			if (*ar == 'd' && !del_history_at(args))
				return (0);
			if (*ar == 'a' && !append_history(args))
				return (0);
			if (*ar == 'n' && !history_non_read())
				return (0);
			if (*ar == 'r' && !history_read(args))
				return (0);
			if (*ar == 'w' && !write_history(args))
				return (0);
			if (*ar == 'e' && !history_exe(args))
				return (0);
			ar++;
		}
		return (1);
	}
	return (-1);
}

/*
** Redistribute action if there is argument, else if no arguments show
** history, else show history at index i.
*/

static int		redistribute_action(char *ar, char **args)
{
	char	*s;
	int		i;

	if ((i = exec_arguments(ar, args) != -1))
		return (i);
	s = get_first_arg(args);
	if (s == NULL)
		return (show_history(&g_shell));
	i = ft_atoi(s);
	if (i >= 0 && i < (int)HISTORY_DATA->elements)
	{
		ft_printf(" * %i %s\n", i, HISTORY_DATA->list[i]);
		return (1);
	}
	return (1);
}

/*
** Show all history command that the user has typed and show the index of them
** Arguments are decanwr
*/

int				b_history(char **args, t_shell *shell)
{
	char ar[9];

	(void)shell;
	ar[0] = 0;
	if (ft_strequ(get_first_arg(args), "help"))
		return (history_help());
	parse_arguments(args, ar, "decanwr");
	if (check_errors(ar))
		return (0);
	return (redistribute_action(ar, args));
}
