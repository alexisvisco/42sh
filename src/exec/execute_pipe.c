/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execute_pipe.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 12:05:55 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 17:57:19 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		exec_all_pipe(char ***argv, int fd)
{
	int		p[2];
	pid_t	pid;
	int		fd_in;
	int		status;
	char	**envp;

	fd_in = 0;
	envp = env_to_array();
	status = 0;
	while (*argv)
	{
		pipe(p);
		if ((pid = fork()) == 0)
		{
			dup2(fd_in, STDIN_FILENO); //change the input according to the old one
			if (*(argv + 1))
				dup2(p[WRITE_END], STDOUT_FILENO);
			else if (*(argv + 1) == NULL && fd != 1)
				dup2(fd, STDOUT_FILENO);
			close(p[READ_END]);
			execve((*argv)[0], *argv, envp);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
			close((*(argv + 1) == NULL && fd != 1) ? fd : p[WRITE_END]);
			fd_in = p[READ_END]; //save the input for the next command
			argv++;
		}
	}
	free_tab(envp);
	return (WEXITSTATUS(status));
}
