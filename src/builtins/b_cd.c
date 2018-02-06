/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_cd.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:56:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 21:22:56 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		b_cd(char **args, t_shell *shell)
{
	char cwd[2048];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		err_builtins(ERR_CD, NULL);
		return (0);
	}
	if (access(args[0] == NULL
	? ht_get(shell->env, "HOME") : args[0], R_OK) == -1)
	{
		err_builtins(ERR_CD_ACCESS, args[0] == NULL
		? ht_get(shell->env, "HOME") : args[0]);
		return (0);
	}
	if (chdir(args[0] == NULL
	? ht_get(shell->env, "HOME") : args[0]) == -1)
	{
		err_builtins(ERR_CD_DIR, args[0]);
		return (0);
	}
	ht_set(shell->env, "OLDPWD", ft_strdup(cwd));
	ht_set(shell->env, "PWD", ft_strdup(getcwd(cwd, sizeof(cwd))));
	msg_builtins(MSG_CD, getcwd(cwd, sizeof(cwd)));
	return (1);
}
