/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec_str.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/28 11:12:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/28 11:12:46 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void     child_fork(const char *argv[], const int *p)
{
	char            **envp;

	envp = env_to_array();
	dup2(p[WRITE_END], STDOUT_FILENO);
	close(p[READ_END]);
	close(STDERR_FILENO);
	execve(argv[0], (char *const *) argv, envp);
	free_tab(envp);
	exit(EXIT_FAILURE);
}


static void     set_str(const int *p, char **ret)
{
	char *line;
	char *tmp;

	while (get_next_line(p[READ_END], &line))
	{
		tmp = *ret;
		*ret = ft_mine_strjoin(*ret, line);
		free(tmp);
		free(line);
	}
	free_gnl();
}

char *exec_to_str(const char *argv[])
{
	int		p[2];
	char		*ret;

	pipe(p);
	if (fork() == 0)
		child_fork(argv, p);
	else
		close(p[WRITE_END]);
	wait(NULL);
	ret = ft_strnew(1);
	set_str(p, &ret);
	return (ret);
}
