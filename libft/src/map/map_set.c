/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_set.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 13:57:00 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/02 12:50:38 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	map_set(t_map *map, char *key, char *value)
{
	t_list	*lst;
	t_entry	*entry;
	t_entry	*tmp;

	lst = map->lst;
	while (lst)
	{
		tmp = (t_entry *)lst->content;
		if (tmp && ft_strequ(key, tmp->key))
		{
			free(tmp->value);
			tmp->value = ft_strdup(value);
			return ;
		}
		lst = lst->next;
	}
	entry = (t_entry *)malloc(sizeof(t_entry));
	if (!entry)
	{
		return ;
	}
	entry->key = ft_strdup(key);
	entry->value = ft_strdup(value);
	lst_add(&(map->lst), lst_new(entry, sizeof(t_entry)));
	free(entry);
}
