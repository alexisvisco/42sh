/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec_pipe.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 14:22:23 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 12:44:06 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void		child_fork(char ***argv, int fd, const int *p)
{
	char			**envp;

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

static int		built_in(char ***argv, int fd)
{
	t_builtins_fun	*buitlin;

	if ((buitlin = builtins(*argv[0])))
		;
	else
		return (-1);
	if (fd != 1)
		dup2(fd, STDOUT_FILENO);
	return (buitlin(*argv, &g_shell));
}

/*
** dup2(input_file != 0 ? input_file : save_fd, STDIN_FILENO); =
** change the input according to the old output
**
**	save_fd = (g_ret == -1) ? p[READ_END] : fd;
** save the input
*/

int	g_ret;

static void		close_fd(const int *p, int *status, t_fd *fd, char ****av)
{
	if (g_ret == -1)
		wait(status);
	else
		close(STDOUT_FILENO);
	if ((*fd).input > 0)
		close((*fd).input);
	(*fd).save = (g_ret == -1) ? p[READ_END] : (*fd).output;
	close(((*fd).output != 1) ? (*fd).output : p[WRITE_END]);
	if (g_ret != -1)
		dup(STDIN_FILENO);
	(*av)++;
}

int				exec_cmds(char ***argv)
{
	int		p[2];
	int		status;
	t_fd	fd;

	fd.save = 0;
	status = 0;
	while (*argv)
	{
		pipe(p);
		if ((fd.output = call_right_redir(*argv)) == -1)
			return (1);
		if ((fd.input = call_left_redir(*argv)) == -1)
			return (1);
		if ((g_ret = built_in(argv, fd.output)) != -1)
			status = (g_ret == 1) ? 0 : 256;
		if (g_ret == -1 && (fork()) == 0)
		{
			dup2(fd.input != 0 ? fd.input : fd.save, STDIN_FILENO);
			child_fork(argv, fd.output, p);
		}
		else
			close_fd(p, &status, &fd, &argv);
	}
	return (WEXITSTATUS(status));
}
