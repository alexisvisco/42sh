/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   central_exec.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 17:25:56 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 18:24:09 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	is_executable(char *path)
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

void		exec_a_block(char **argv)
{
	char	*node;
	int		ret;

	node = NULL;
	ret = 0;
	if (is_executable(argv[0]))
		ret = fork_result(argv[0], argv);
	else if ((node = ht_get(g_shell.bin, argv[0])))
		ret = fork_result(node, argv);
	else
		e_general(ERR_CMD_NOT_FOUND, argv[0]);
	printf("ret %i\n\n", ret);
}

void		exec_all(t_token **tokens, t_block *blocks)
{
	int		i;
	char	**argv;

	i = 0;
	while (blocks[i].start_tok != -1)
	{
		argv = extract_cmd_args(tokens, blocks, i);
		exec_a_block(argv);
		free_tab(argv);
		i++;
	}
}
