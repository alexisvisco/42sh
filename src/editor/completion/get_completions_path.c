/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_completions_path.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 10:39:36 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 11:29:56 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void	get_completions_path_a(char *folder, char *start, t_heap *heap)
{
	struct dirent	*dent;
	DIR				*dir;
	char			*to_add;

	dir = opendir(folder);
	if (!dir)
		return ;
	while ((dent = readdir(dir)) != NULL)
	{
		if (ft_strstarts_with_str(start, dent->d_name))
		{
			to_add = get_next_str(start, dent->d_name);
			heap_add(heap, ft_strdup(to_add));
			free(to_add);
			to_add = NULL;
		}
	}
	free(dir);
}

void		get_completions_path(t_word_info *i, t_heap *heap)
{
	char *folder;
	char *start_with;
	char *has_slash;

	has_slash = 0;
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
	get_completions_path_a(folder, start_with, heap);
	free(folder);
	free(start_with);
}
