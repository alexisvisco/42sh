/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_set.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 13:57:00 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
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
			ft_memdel((void **)&(tmp->value));
			tmp->value = ft_strdup(value);
			return ;
		}
		lst = lst->next;
	}
	entry = (t_entry *)ft_memalloc(sizeof(t_entry));
	if (!entry)
	{
		return ;
	}
	entry->key = ft_strdup(key);
	entry->value = ft_strdup(value);
	lst_add(&(map->lst), lst_new(entry, sizeof(t_entry)));
	ft_memdel((void **)&entry);
}
