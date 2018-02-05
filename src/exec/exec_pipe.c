/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec_pipe.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 12:05:55 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 19:19:04 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void     child_fork(char ***argv, int fd, const int *p)
{
	char	**envp;

	envp = env_to_array();
	if (*(argv + 1))
		dup2(p[WRITE_END], STDOUT_FILENO);
	else if (*(argv + 1) == NULL && fd != 1)
		dup2(fd, STDOUT_FILENO);
	close(p[READ_END]);
	execve((*argv)[0], *argv, envp);
	free_tab(envp);
	exit(EXIT_FAILURE);
}

int		exec_all_pipe(char ***argv, int fd)
{
	int		p[2];
	int		save_fd;
	int		status;
	int		input_file;

	save_fd = 0;
	status = 0;
	while (*argv)
	{
		pipe(p);
		if ((input_file = call_left_redir(*argv)) == -1)
			return (1);
		if ((fork()) == 0)
		{
			if (input_file != 0)
				dup2(input_file, STDIN_FILENO);
			dup2(input_file != 0 ? input_file : save_fd, STDIN_FILENO); //change the input according to the old one
			child_fork(argv, fd, p);
		}
		else
		{
			wait(&status);
			if (input_file != 0)
      		{
				close(input_file);
				input_file = 0;
      		}
			close((*(argv + 1) == NULL && fd != 1) ? fd : p[WRITE_END]);
			save_fd = p[READ_END]; //save the input for the next command
			argv++;
		}
	}
	return (WEXITSTATUS(status));
}
