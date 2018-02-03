/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fork.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 17:25:56 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 18:46:36 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** USELESS
*/

int			fork_result(char *node, char **argv)
{
	int		status;
	pid_t	childpid;
	char	**newenv;

	status = 0;
	newenv = env_to_array();
	childpid = fork();
	if (childpid == 0)
		execve(node, argv, newenv);
	else if (childpid > 0)
		wait(&status);
	else
		perror("Fork failed");
	free_tab(newenv);
	return (WEXITSTATUS(status));
}
