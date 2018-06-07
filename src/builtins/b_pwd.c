/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_pwd.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:56:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
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
	(void)shell;
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		ft_printf("%s\n", cwd);
	else
	{
		message_err(ERR_PWD_NOT_FOUND);
		return (0);
	}
	return (1);
}
