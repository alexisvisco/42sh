/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_getv.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 13:59:17 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*map_getv(t_map *map, char *key)
{
	t_entry *tmp;

	tmp = map_get(map, key);
	return (tmp ? tmp->value : (NULL));
}
