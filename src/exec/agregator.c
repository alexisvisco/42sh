/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   agregator.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 13:08:19 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	agregator(char *str, int p[2])
{
	char todo = 2;
	// METTRE LES STDOUT CORRECTEMENT ET TESTER !!!
	// faire les >&- >&1 >&2
	(void)todo;
	if (ft_strequ(str, "2>&1") || ft_strequ(str, "1<&2"))
		dup2(p[WRITE_END], STDERR_FILENO);
	else if (ft_strequ(str, "1>&2") || ft_strequ(str, "2<&1"))
		dup2(STDERR_FILENO, p[WRITE_END]);
	else if (ft_strequ(str, "1>&0") || ft_strequ(str, "0<&1"))
		dup2(STDIN_FILENO, p[WRITE_END]);
	else if (ft_strequ(str, "0>&1") || ft_strequ(str, "1<&0"))
		dup2(p[WRITE_END], STDIN_FILENO);
	else if (ft_strequ(str, "2>&0") || ft_strequ(str, "0<&2"))
		dup2(STDIN_FILENO, STDERR_FILENO);
	else if (ft_strequ(str, "0>&2") || ft_strequ(str, "2<&0"))
		dup2(STDERR_FILENO, STDIN_FILENO);
	else if (ft_strequ(str, "0>&-") || ft_strequ(str, "0<&-"))
		close(STDIN_FILENO);
	else if (ft_strequ(str, "1>&-") || ft_strequ(str, "1<&-"))
		close(STDOUT_FILENO);
	else if (ft_strequ(str, "2>&-") || ft_strequ(str, "2<&-"))
		close(STDERR_FILENO);
	else
		return (-1);
	return (1);
}

int			analyze_agreg(char ***cmds, int p[2])
{
	int	k;

	k = 0;
	while ((*cmds)[k])
	{
		if (agregator((*cmds)[k], p) == 1)
		{
			tab_del_from_to(cmds, k, k);
			return (1);
		}
		k++;
	}
	return (-1);
}
