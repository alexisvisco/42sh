/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   delete_redir.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 17:51:00 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int			delete_redir_and_dup(char ***cmds, int file)
{
	int	k;

	k = 0;
	while ((*cmds)[k])
	{
		if (ft_strequ((*cmds)[k], ">>") || ft_strequ((*cmds)[k], ">"))
		{
			dup2(file, STDOUT_FILENO);
			break ;
		}
		if (ft_isdigit((*cmds)[k][0]))
		{
			if (ft_strequ((*cmds)[k] + 1, ">>") ||
					ft_strequ((*cmds)[k] + 1, ">"))
			{
				dup2(file, (*cmds)[k][0] - '0');
				break ;
			}
		}
		k++;
	}
	if ((*cmds)[k] == NULL)
		return (1);
	tab_del_from_to(cmds, k, k + 1);
	return (file);
}
