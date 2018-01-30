/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_bin.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 10:43:16 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 11:22:29 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void	path_join(char *path, char *path_folder, char *file_path_folder)
{
	ft_strcpy(path, path_folder);
	ft_strcat(path, "/");
	ft_strcat(path, file_path_folder);
}

static int	can_use(char *path)
{
	struct stat st;

	return ((access(path, X_OK) != -1) && (stat(path, &st) == 0
	&& st.st_mode & S_IXUSR));
}

static void	add_to_bintable(char *path_folder)
{
	DIR				*dir;
	struct dirent	*entry;
	char			path[2048];
	char			*tmp;

	if (!(dir = opendir(path_folder)))
		return ;
	while ((entry = readdir(dir)) != NULL)
	{
		path_join((char *)path, path_folder, entry->d_name);
		if (!(ft_strequ(entry->d_name, ".") || ft_strequ(entry->d_name, ".."))
		&& can_use(path))
		{
			tmp = ft_strdup(path);
			ht_set(g_shell.bin, entry->d_name, tmp);
		}
	}
	closedir(dir);
}

void		set_bin(void)
{
	char	*path;
	char	**paths;
	int		i;

	g_shell.bin = ht_new(512);
	path = (char *)ht_has(g_shell.env, "PATH")->value;
	if (path)
	{
		paths = ft_strsplit(path, ':');
		i = -1;
		while (paths[++i])
			add_to_bintable(paths[i]);
		free_tab(paths);
	}
}
