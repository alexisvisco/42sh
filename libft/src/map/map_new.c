/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_new.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 13:50:03 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_map	*map_new(void)
{
	t_map	*map;

	map = ft_memalloc(sizeof(t_map));
	map->lst = NULL;
	return (map);
}
