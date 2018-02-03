/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   return_executable.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 10:55:20 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 17:02:47 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int			is_executable(char *path)
{
	struct stat st;

	return ((access(path, X_OK) != -1) && (stat(path, &st) == 0
	&& st.st_mode & S_IXUSR));
}

int			replace_argv0_by_exec(char ***cmds)
{
	int		i;
	char	*tmp;

	i = 0;
	while (cmds[i])
	{
		if (is_executable(cmds[i][0]))
			;
		/*
		** else if (is a buildin)
		*/
		else if ((tmp = ht_get(g_shell.bin, cmds[i][0])))
		{
			free(cmds[i][0]);
			cmds[i][0] = ft_strdup(tmp);
		}
		else
		{
			e_general(ERR_CMD_NOT_FOUND, cmds[i][0]);
			return (-1);
		}
		i++;
	}
	return (0);
}
