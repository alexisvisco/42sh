/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec_bacquotes.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/19 14:57:51 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 20:22:37 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

#define INPUT_RED (fd.input = call_left_redir(argv)) == -1
#define OUTPUT_AGREG (fd.output = call_ag_redir(argv)) == -1
#define OUTPUT_RED (fd.output = call_right_redir(argv)) == -1

static int			my_execve(char **const *argv, char *const *envp)
{
	int a;

	a = -1;
	if (is_directory((*argv)[0]))
		message_err(ERR_IS_DIR, (*argv)[0]);
	else
		execve((*argv)[0], *argv, envp);
	return (a);
}

static void			child_fork(char ***argv, t_fd fd, int *p)
{
	char			**envp;
	t_builtins_fun	*buitlin;
	int				a;

	envp = env_to_array(g_shell.env);
	analyze_agreg(argv, p);
	dup2(fd.input != 0 ? fd.input : fd.save, STDIN_FILENO);
	dup2(p[WRITE_END], STDOUT_FILENO);
	if (fd.output != 1)
		delete_redir_and_dup(argv, fd.output);
	close(p[READ_END]);
	if ((buitlin = builtins((*argv)[0])) && !(is_builtins_env((*argv)[0])))
	{
		a = buitlin(*argv, &g_shell);
		exit_shell();
	}
	else
		a = my_execve(argv, envp);
	free_tab(envp);
	exit(a == -1 ? EXIT_FAILURE : !a);
}

/*
** dup2(input_file != 0 ? input_file : save_fd, STDIN_FILENO); =
** change the input according to the old output
**
**  save_fd = (g_ret == -1) ? p[READ_END] : fd;
** save the input
*/

static void			close_fd(const int *p, t_fd *fd, char ****av)
{
	if ((*fd).input > 0)
		close((*fd).input);
	if ((*fd).output != 1)
		close((*fd).output);
	close(p[WRITE_END]);
	if ((*fd).save)
		close((*fd).save);
	(*fd).save = p[READ_END];
	(*av)++;
}

t_backquotes		exec_backquotes(char ***argv)
{
	int				p[2];
	int				status;
	t_fd			fd;
	t_backquotes	ret;

	fd.save = 0;
	status = 0;
	while (*argv)
	{
		pipe(p);
		if (INPUT_RED || OUTPUT_AGREG || (fd.output == 1 && OUTPUT_RED))
			return (error_redir(&ret));
		if ((fork()) == 0)
			child_fork(argv, fd, p);
		else
			close_fd(p, &fd, &argv);
	}
	get_backq_status(status, &ret);
	if (fd.output == 1)
		get_backq_string(p, &ret);
	return (ret);
}
