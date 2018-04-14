/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   agregator_to_file.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 13:56:35 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	open_agreg_redir(char **str, int flag, int i)
{
	int	file;

	if (str[i + 1] == NULL)
		return (-1);
	file = open(str[i + 1], O_WRONLY | O_CREAT | flag, 0644);
	if (file < 0)
	{
		if (errno == EISDIR)
			message_err(ERR_IS_DIR, str[i + 1]);
		else if (access(str[i + 1], X_OK) == -1)
			message_err(ERR_ACCES, str[i + 1]);
		else
			message_err(ERR_EXIST, str[i + 1]);
	}
	return (file);
}

int			call_ag_redir(char ***cmds)
{
	int	k;
	int	fd;

	k = 0;
	fd = 1;
	while ((*cmds)[k])
	{
		if (ft_isdigit((*cmds)[k][0]))
		{
			if (ft_strequ((*cmds)[k] + 1, ">>"))
			{
				fd = open_agreg_redir((*cmds), O_APPEND, k);
				break ;
			}
			else if (ft_strequ((*cmds)[k] + 1, ">"))
			{
				fd = open_agreg_redir((*cmds), O_TRUNC, k);
				break ;
			}
		}
		k++;
	}
	if ((*cmds)[k] == NULL)
		return (1);
	return (fd);
}
