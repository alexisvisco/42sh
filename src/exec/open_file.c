/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   open_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/03 18:41:11 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 15:47:32 by ggranjon    ###    #+. /#+    ###.fr     */
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

int			call_right_redir(char ***cmds)
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

static void	error_left_redir(int fd, int k, char ***cmds)
{
	if (fd < 0)
	{
		if (errno == EISDIR)
			e_open(ERR_IS_DIR, cmds[0][k + 1]);
		else if (access(cmds[0][k + 1], X_OK) == -1)
			e_open(ERR_PERM, cmds[0][k + 1]);
		else
			e_open(ERR_EXIST, cmds[0][k + 1]);
	}
}

int			call_left_redir(char ***cmds)
{
	int	k;
	int	fd;

	k = 0;
	fd = 0;
	while (cmds[0][k])
	{
		if (ft_strequ(cmds[0][k], "<"))
		{
			fd = open(cmds[0][k + 1], O_RDONLY, 0644);
			break ;
		}
		k++;
	}
	error_left_redir(fd, k, cmds);
	if (cmds[0][k] == NULL)
		return (0);
	free(cmds[0][k]);
	free(cmds[0][k + 1]);
	cmds[0][k] = NULL;
	return (fd);
}