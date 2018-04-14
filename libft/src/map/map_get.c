/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 13:59:17 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_entry		*map_get(t_map *map, char *key)
{
	t_list	*lst;
	t_entry	*tmp;

	lst = map->lst;
	while (lst)
	{
		tmp = (t_entry *)lst->content;
		if (ft_strequ(key, tmp->key))
			return (tmp);
		lst = lst->next;
	}
	return (NULL);
}
