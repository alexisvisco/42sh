/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   paths.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/20 18:04:43 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/20 18:04:43 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#define LAST(rsl) ((int)ft_strlen(rsl) - 1)

static void prev_path(char **cur)
{
	int		i;
	int		s;
	char	**splitted;

	splitted = ft_strsplit(*cur, '/');
	s = (int)(size_tab(splitted) - 1);
	i = 0;
	if (s <= 0)
		ft_strcpy(*cur, "/");
	else
	{
		if (*cur[0] == '/')
		{
			ft_strcpy(*cur, "/");
			ft_strcat(*cur, splitted[0]);
		}
		else if (splitted)
			ft_strcpy(*cur, splitted[0]);
		while (splitted && splitted[++i] && i < s)
		{
			ft_strcat(*cur, "/");
			ft_strcat(*cur, splitted[i]);
		}
	}
	free_tab(splitted);
}

static char *prev_or_concat(int i, char **rsl, char **splitted)
{
	if (ft_strequ(splitted[i], ".."))
			prev_path(rsl);
	else if (!ft_strequ(splitted[i], "."))
	{
		if (LAST(*rsl) > 1 && (*rsl)[LAST(*rsl)] != '/')
			ft_strcat((*rsl), "/");
		ft_strcat((*rsl), splitted[i]);
	}
	return (*rsl);
}

char *force_symbolic_link(char *cur, char *path)
{
	int		i;
	char	*rsl;
	char	**splitted;

	rsl = ft_memalloc(4096);
	splitted = ft_strsplit(path, '/');
	if (path[0] != '/')
	{
		rsl[0] = 0;
		ft_strcpy(rsl, cur);
	}
	else
		ft_strcpy(rsl, "/");
	i = -1;
	while (splitted && splitted[++i])
		rsl = prev_or_concat(i, &rsl, splitted);
	if (LAST(rsl) >= 0 && rsl[LAST(rsl)] != '/')
		ft_strcat(rsl, "/");
	free_tab(splitted);
	return rsl;
}
