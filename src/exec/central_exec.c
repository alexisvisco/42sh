/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   central_exec.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 17:25:56 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 14:48:42 by ggranjon    ###    #+. /#+    ###.fr     */
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

/*
** if ret = 1 > erreur else ret = 0
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
