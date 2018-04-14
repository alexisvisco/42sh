/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   c_uintmax.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 09:09:01 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int16_t		len_uintmax(uintmax_t v, uint8_t base)
{
	int16_t ret;

	ret = 1;
	while (v /= base)
		++ret;
	return (ret);
}

int16_t		str_uintmax(char *dst, uintmax_t n, uint8_t base,
const char *digits)
{
	int16_t	i;
	int16_t	x;

	if (base > 36)
		return (0);
	i = len_uintmax(n, base);
	x = i;
	dst[x] = 0;
	x--;
	if (n == 0)
	{
		dst[0] = '0';
		return (2);
	}
	while (n)
	{
		dst[x--] = digits[n % base];
		n /= base;
	}
	return ((uint8_t)(i + 1));
}
