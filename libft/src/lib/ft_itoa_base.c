/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/09 13:34:25 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 14:25:15 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int value, int base)
{
	int		i;
	long	nb;
	char	*res;

	nb = value < 0 ? -(long)value : (long)value;
	i = value == 0 || (value < 0 && base == 10) ? 1 : 0;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	if (!(res = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	res[i--] = '\0';
	nb = value < 0 ? -(long)value : (long)value;
	while (i >= 0)
	{
		res[i] = (nb % base) >= 10 ? (nb % base) + 65 - 10 : (nb % base) + 48;
		nb /= base;
		i--;
	}
	res[0] = value < 0 && base == 10 ? '-' : res[0];
	return (res);
}
