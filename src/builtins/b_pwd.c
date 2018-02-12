/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_pwd.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:56:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 11:46:33 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Show the current working directory
** Take no arguments
*/

int		b_pwd(char **args, t_shell *shell)
{
	char cwd[2048];

	(void)args;
	if (ht_get(shell->env, "PWD"))
		ft_printf("%s\n", ht_get(shell->env, "PWD"));
	else if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		ft_printf("%s\n", cwd);
		ht_set(shell->env, "PWD", cwd);
	}
	else
	{
		message_err(ERR_PWD_NOT_FOUND);
		return (0);
	}
	return (1);
}
