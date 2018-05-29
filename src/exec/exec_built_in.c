/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec_built_in.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/14 13:56:54 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:57:33 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		exec_built_in(char ***argv, t_block *blocks, t_token **tok)
{
	t_builtins_fun	*buitlin;
	int				i;

	i = 0;
	if (is_assignation_variable(*argv[0]))
		return (create_variable(*argv[0]));
	if ((buitlin = builtins_env(*argv[0])))
	{
		if (ft_strequ(*argv[0], "exit") || ft_strequ(*argv[0], "quit"))
		{
			while (tok[i])
			{
				free(tok[i]->value);
				free(tok[i]);
				i++;
			}
			free(tok);
			free(blocks);
		}
	}
	else
		return (-1);
	return (buitlin(*argv, &g_shell));
}
