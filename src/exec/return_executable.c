/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   return_executable.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 10:55:20 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 11:23:57 by ggranjon    ###    #+. /#+    ###.fr     */
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

int			node_return(char **argv, char **node)
{
	if (is_executable(argv[0]))
	{
		(*node) = argv[0];
		return (1);
	}
	/* if (is a buildin)
	**
	*/
	else if (((*node) = ht_get(g_shell.bin, argv[0])))
		return (1);
	return (0);
}
