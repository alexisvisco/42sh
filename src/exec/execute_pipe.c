/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execute_pipe.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 12:05:55 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 19:16:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char		***take_all_argv(t_token **tokens, t_block *block, int num)
{
	char	***cmds;

	cmds = malloc(sizeof(char**) * (block[num].nb_pipe + 1));
}

void		exec_all_pipe(char ***argv, char *node)
{
	int		p[2];
	pid_t	pid;
	int		fd_in;

	fd_in = 0;
	while (*argv != NULL)
	{
		pipe(p);
		if ((pid = fork()) == 0)
		{
			dup2(fd_in, 0); //change the input according to the old one
			if (*(argv + 1) != NULL)
				dup2(p[1], 1);
			close(p[0]);
			execve((*argv)[0], *argv, NULL);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
			close(p[1]);
			fd_in = p[0]; //save the input for the next command
			argv++;
		}
	}
}
