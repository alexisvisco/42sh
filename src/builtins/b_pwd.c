/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_pwd.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:56:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 19:23:34 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int     b_pwd(char **args, t_hashtable *envs)
{
	char cwd[2048];

	(void)args;
	if (ht_get(envs, "PWD"))
		ft_printf("%s\n", ht_get(envs, "PWD"));
	else if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		ft_printf("%s\n", cwd);
		ht_set(envs, "PWD", cwd);
	}
	else
	{
		err_builtins(ERR_PWD_NOT_FOUND);
		return (0);
	}
	return (1);
}