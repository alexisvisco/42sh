/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_completions_path.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 10:39:36 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 10:35:47 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void	path_join(char *path, char *path_folder, char *file_path_folder)
{
	ft_strcpy(path, path_folder);
	if (!ft_strends_with(path_folder, '/'))
		ft_strcat(path, "/");
	ft_strcat(path, file_path_folder);
}

static void	get_completions_path_a(char *folder, char *start, char *origin,
t_heap *heap)
{
	struct dirent	*dent;
	DIR				*dir;
	char			path[2048];
	char			*tmp;

	dir = opendir(folder);
	if (!dir)
		return ;
	while ((dent = readdir(dir)) != NULL)
	{
		if (*start == 0 || ft_strstarts_with_str(dent->d_name, start))
		{
			path_join(path, folder, dent->d_name);
			if (ft_strstarts_with(folder, '.') &&
				!ft_strstarts_with(origin, '.'))
			{
				tmp = ft_strrep_first_aft("./", "", path, 0);
				heap_add(heap, tmp);
			}
			else
				heap_add(heap, ft_strdup(path));
		}
	}
	closedir(dir);
}

/*
** Get all completions possible for i->current_word that is a path
** If there is no word or word is empty search paths with '.'
*/

void		get_completions_path(t_word_info *i, t_heap *heap)
{
	char *folder;
	char *start_with;
	char *has_slash;

	if (i->current_word != NULL)
	{
		has_slash = ft_strchr(i->current_word, '/');
		folder = has_slash ? get_folder_from(i->current_word) : ft_strdup(".");
		start_with = has_slash ?
		get_name_from(i->current_word) : ft_strdup(i->current_word);
	}
	else
	{
		folder = ft_strdup(".");
		start_with = ft_strdup("");
	}
	get_completions_path_a(folder, start_with, i->current_word, heap);
	free(folder);
	free(start_with);
}
