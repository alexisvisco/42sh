/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_cd.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:56:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <shell.h>

#define MOVE(s) cd_is_ok(s) && move(s)

static int 		move(char *path)
{
	char pwd[4096];
	char *tmp;

	if (!path)
		return -1;
	if (chdir(path) == -1)
	{
		message_err(ERR_CD_ACCESS, path);
		return 0;
	}
	tmp = ft_strdup(path);
	if (get_cwd(pwd, sizeof(pwd)))
		ht_set(g_shell.env, "OLDPWD", ft_strdup(pwd));
	ht_set(g_shell.env, "PWD", tmp);
	return 1;
}

static int		cd_is_ok(char *path)
{
	struct stat	s;

	if (!*path || lstat(path, &s) != 0)
	{
		message_err(ERR_CD_ACCESS, path);
		return 0;
	}
	if (!S_ISDIR(s.st_mode) && !S_ISLNK(s.st_mode))
	{
		message_err(ERR_CD_DIR, path);
		return 0;
	}
	if ((!S_ISLNK(s.st_mode) && access(path, R_OK) != 0) ||
		access(path, X_OK) != 0)
	{
		message_err(ERR_CD_ACCESS, path);
		return 0;
	}
	return (1);
}

static int 		cd_path(char *path, int p, int no_args)
{
	char		*rpath;
	char		cwd[4096];
	int			res;

	if (no_args && !path)
	{
		if (ht_get(g_shell.env, "HOME"))
			return MOVE(ht_get(g_shell.env, "HOME"));
		message_err(ERR_CD);
		return 0;
	}
	else if (path && path[0] == '-' && ft_strlen(path) == 1)
	{
		if (ht_get(g_shell.env, "OLDPWD"))
			return MOVE(ht_get(g_shell.env, "OLDPWD"));
		message_err(ERR_NO_OLD_PWD);
		return 0;
	}
	else if (!p && path)
	{
		if (ht_get(g_shell.env, "PWD"))
		{
			rpath = force_symbolic_link(ht_get(g_shell.env, "PWD"), path);
			res = MOVE(rpath);
			free(rpath);
			return res;
		}
		else
		{
			message_err(ERR_CD);
			return 0;
		}
	}
	else if (path)
	{
		if (cd_is_ok(path) && chdir(path) != 1)
		{
			getcwd(cwd, sizeof(cwd));
			ht_set(g_shell.env, "PWD", ft_strdup(cwd));
			return 1;
		}
	}
	return (0);
}

/*
** Change the current directory, if no arguments, go to home, if argument is a
** '-' go to the previous working directory, if its a valid argument and
** accessible path, go to the argument path
**
** Usage -P into absolute path
*/

int			b_cd(char **args, t_shell *shell)
{
	int		p;
	(void)shell;

	p = (size_tab(args) == 3 && ft_strcmp("-P", args[1]) == 0);
	if (size_tab(args) > 3)
	{
		message(USAGE_CD);
		return 0;
	}
	return cd_path(p ? args[2] : args[1], p, size_tab(args) == 1);
}
