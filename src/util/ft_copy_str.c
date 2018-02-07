/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_copy_str.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 19:56:38 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 14:46:31 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
**  Copy str in src to dest
*/

void	ft_copy_str(char *dest, char *src)
{
	size_t i;

	i = 0;
	while (dest && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}