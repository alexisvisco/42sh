/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ht_hash.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 14:47:15 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 18:44:57 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ht_hash(const char *key)
{
	const size_t	len = ft_strlen(key);
	size_t			hash;
	size_t			i;
	
	i = 0;
	hash = i;
	while (i < len)
	{
		hash += key[i];
		hash += hash << 10;
		hash ^= hash >> 6;
		i++;
	}
    hash += (hash << 3);
	hash ^= ( hash >> 11 );
	hash += ( hash << 15 );
	return (hash);
}
