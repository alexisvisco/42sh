/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec_pipe.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 14:22:23 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 13:26:21 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

#define INPUT_FILE_REDIR (fd.input = call_left_redir(argv)) == -1
#define INPUT_FILE_HEREDOC (fd.input = call_heredoc(argv, fd.input)) == -1
#define OUTPUT_AGREG (fd.output = call_ag_redir(argv)) == -1

static void		child_fork(char ***argv, int fd, const int *p)
{
	char			**envp;
	t_builtins_fun	*buitlin;
	int				a;

	envp = env_to_array();
	if (*(argv + 1) && fd == 1)
		dup2(p[WRITE_END], STDOUT_FILENO);
	else if (fd != 1)
		delete_redir_and_dup(argv, fd);
	close(p[READ_END]);
	if ((buitlin = builtins((*argv)[0])))
	{
		a = buitlin(*argv, &g_shell);
		exit_shell();
	}
	else
	{
		a = -1;
		execve((*argv)[0], *argv, envp);
	}
	free_tab(envp);
	exit(a == -1 ? EXIT_FAILURE : !a);
}

static int		built_in(char ***argv, t_block *blocks, t_token **tok)
{
	t_builtins_fun	*buitlin;
	int				i;

	i = 0;
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

/*
** dup2(input_file != 0 ? input_file : save_fd, STDIN_FILENO); =
** change the input according to the old output
**
**  save_fd = (g_ret == -1) ? p[READ_END] : fd;
** save the input
*/
int	g_ret;

static void		close_fd(const int *p, int *status, t_fd *fd, char ****av)
{
	if (g_ret == -1)
		wait(status);
	if ((*fd).input > 0)
		close((*fd).input);
	(*fd).save = p[READ_END];
	close(((*fd).output != 1) ? (*fd).output : p[WRITE_END]);
	(*av)++;
}

int				exec_cmds(char ***argv, t_block *blocks, t_token **tokens)
{
	int		p[2];
	int		status;
	t_fd	fd;

	fd.save = 0;
	status = 0;
	while (*argv)
	{
		pipe(p);
		if (INPUT_FILE_REDIR || INPUT_FILE_HEREDOC || OUTPUT_AGREG ||
			(fd.output == 1 && (fd.output = call_right_redir(argv)) == -1))
			return (1);
		if ((g_ret = built_in(argv, blocks, tokens)) != -1)
			status = (g_ret == 1) ? 0 : 256;
		if (g_ret == -1 && (fork()) == 0)
		{
			analyze_agreg(argv);
			dup2(fd.input != 0 ? fd.input : fd.save, STDIN_FILENO);
			child_fork(argv, fd.output, p);
		}
		else
			close_fd(p, &status, &fd, &argv);
	}
	return (WEXITSTATUS(status));
}
