/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_getv.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 13:59:17 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/02 12:54:37 by aviscogl    ###    #+. /#+    ###.fr     */
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
