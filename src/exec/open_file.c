/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   open_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/03 18:41:11 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 19:22:49 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	open_right_redir(char **str, int flag, int i)
{
	int	file;

	if (str[i + 1] == NULL)
		return (-1);
	file = open(str[i + 1], O_WRONLY | O_CREAT | flag, 0644);
	if (file < 0)
	{
		if (errno == EISDIR)
			e_open(ERR_IS_DIR, str[i + 1]);
		else if (access(str[i + 1], X_OK) == -1)
			e_open(ERR_PERM, str[i + 1]);
	}
	return (file);
}

int			call_redir(char ***cmds)
{
	int	i;
	int	k;
	int	fd;

	i = 0;
	while (cmds[i])
		i++;
	i--;
	k = 0;
	while (cmds[i][k])
	{
		if (ft_strequ(cmds[i][k], ">>"))
		{
			fd = open_right_redir(cmds[i], O_APPEND, k);
			break ;
		}
		else if (ft_strequ(cmds[i][k], ">"))
		{
			fd = open_right_redir(cmds[i], O_TRUNC, k);
			break ;
		}
		k++;
	}
	if (cmds[i][k] == NULL)
		return (1);
	free(cmds[i][k]);
	free(cmds[i][k + 1]);
	cmds[i][k] = NULL;
	return (fd);
}