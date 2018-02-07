/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_cd.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:56:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 12:01:44 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		b_cd(char **args, t_shell *shell)
{
	char *dir;
	char cwd[2048];

	dir = args[1] == NULL ? ht_get(shell->env, "HOME") : args[1];
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		err_builtins(ERR_CD, NULL);
		return (0);
	}
	if (access(dir, R_OK) == -1)
	{
		err_builtins(ERR_CD_ACCESS, dir);
		return (0);
	}
	if (chdir(dir) == -1)
	{
		err_builtins(ERR_CD_DIR, args[1]);
		return (0);
	}
	ht_set(shell->env, "OLDPWD", ft_strdup(cwd));
	ht_set(shell->env, "PWD", ft_strdup(getcwd(cwd, sizeof(cwd))));
	msg_builtins(MSG_CD, getcwd(cwd, sizeof(cwd)));
	return (1);
}
