/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_del.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 13:53:36 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		del(void *c, size_t s)
{
	t_entry	*tmp;

	(void)s;
	tmp = (t_entry *)c;
	ft_memdel((void **)&(tmp->key));
	ft_memdel((void **)&(tmp->value));
	ft_memdel((void **)&tmp);
}

void			map_del(t_map *map)
{
	t_list	*lst;

	if (map && map->lst)
	{
		lst = map->lst;
		lst_delete(&lst, del);
		map->lst = NULL;
	}
}
