/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_unset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 13:57:00 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	free_map(t_entry *tmp, t_list *prev, t_list *lst, t_map *map)
{
	ft_memdel((void **)&(tmp->value));
	ft_memdel((void **)&(tmp->key));
	if (prev)
		prev->next = lst->next;
	else if (!prev && lst->next)
		map->lst = lst->next;
	else
		map->lst = NULL;
	ft_memdel((void **)&lst);
	lst = NULL;
}

int			map_unset(t_map *map, char *key)
{
	t_list	*lst;
	t_entry	*tmp;
	t_list	*prev;

	lst = map->lst;
	prev = NULL;
	while (lst)
	{
		tmp = (t_entry *)lst->content;
		if (tmp && ft_strequ(key, tmp->key))
		{
			free_map(tmp, prev, lst, map);
			return (1);
		}
		prev = lst;
		lst = lst->next;
	}
	return (0);
}
