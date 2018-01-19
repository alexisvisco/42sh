/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   c_intmax.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 09:09:01 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/03 14:05:24 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int16_t		len_intmax(intmax_t v, uint8_t base)
{
	int16_t ret;

	ret = 1;
	v = v < 0 ? -v : v;
	while (v /= base)
		++ret;
	return (ret);
}

int16_t		str_intmax(char *dst, intmax_t n, uint8_t base, const char *digits)
{
	int16_t	i;
	int16_t	x;

	if (base > 36)
		return (0);
	i = len_intmax(n, base);
	x = 0;
	if (n < 0 && base == 10)
		dst[x] = '-';
	x = (n < 0 && base == 10) ? 1 + i : i;
	dst[x--] = 0;
	if (n == 0)
	{
		dst[0] = '0';
		return (2);
	}
	while (n)
	{
		dst[x--] = digits[(n < 0) ? -(n % base) : (n % base)];
		n /= base;
	}
	return ((uint8_t)(i + 1));
}
