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

static void		child_fork(char ***argv, t_fd fd, int *p)
{
	char			**envp;
	t_builtins_fun	*buitlin;
	int				a;

	envp = env_to_array();
	analyze_agreg(argv, p);
	dup2(fd.input != 0 ? fd.input : fd.save, STDIN_FILENO);
	dup2(p[WRITE_END], STDOUT_FILENO);
	if (fd.output != 1)
		delete_redir_and_dup(argv, fd.output);
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

/*
** dup2(input_file != 0 ? input_file : save_fd, STDIN_FILENO); =
** change the input according to the old output
**
**  save_fd = (g_ret == -1) ? p[READ_END] : fd;
** save the input
*/
int	g_ret;

static void		close_fd(const int *p, t_fd *fd, char ****av)
{
	if ((*fd).input > 0)
		close((*fd).input);
	close(((*fd).output != 1) ? (*fd).output : p[WRITE_END]);
	if ((*fd).save)
		close((*fd).save);
	(*fd).save = p[READ_END];
	(*av)++;
}

static void		get_backq_string(const int *p, t_backquotes *ret)
{
	char *line;
	char *tmp;

	while (get_next_line(p[READ_END], &line) > 0)
	{
		tmp = (*ret).str;
		(*ret).str = ft_mine_strjoin((*ret).str, line);
		ft_memdel((void **)&tmp);
		ft_memdel((void **)&line);
	}
	free_gnl();
}

t_backquotes	error_redir(t_backquotes *ret)
{
	(*ret).status = 1;
	(*ret).str = NULL;
	return (*ret);
}

t_backquotes	exec_backquotes(char ***argv, t_block *blocks, t_token **tokens)
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
		if ((g_ret = exec_built_in(argv, blocks, tokens)) != -1)
			status = (g_ret == 1) ? 0 : 256;
		if (g_ret == -1 && (fork()) == 0)
			child_fork(argv, fd, p);
		else
			close_fd(p, &fd, &argv);
	}
	if (g_ret == -1)
		wait(&status);
	while (wait(NULL) > 0)
		;
	ret.status = WEXITSTATUS(status);
	ret.str = ft_strnew(1);
	if (fd.output == 1)
		get_backq_string(p, &ret);
	return (ret);
}
