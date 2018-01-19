/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_numstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 14:08:08 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/09 19:03:33 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

uint8_t	ft_floatstr(char *dst, float n, int precision, uint8_t base)
{
	uint8_t	l;
	float	d;
	float	di;

	if ((int64_t)n == n)
		return (ft_intstr(dst, (int64_t)n, base));
	d = n - (int64_t)n;
	if (d >= 0.95)
		d = ((int)++n & 0);
	l = ft_intstr(dst, (int64_t)n, base);
	dst[l++] = '.';
	di = precision * d;
	return (l + ft_intstr(dst + l,
		(int64_t)di + ((di - (int64_t)di) >= 0.5 ? 1 : 0), base));
}

uint8_t	ft_uintstr(char *dst, uint64_t n, uint8_t base)
{
	uint8_t		i;
	static char	digits[37] = "0123456789abcdefghijklmnopqrstuvwxyz";

	if (base > 36)
		return (0);
	if (n == 0 || base <= 1)
		return ((uint8_t)(((*dst = '0') & 0) + 1));
	i = math_uintlen(n, base);
	dst += i - 1;
	while (n)
	{
		*dst-- = digits[n % base];
		n /= base;
	}
	return (i);
}

uint8_t	ft_intstr(char *dst, int64_t n, uint8_t base)
{
	uint8_t		i;
	static char	digits[37] = "0123456789abcdefghijklmnopqrstuvwxyz";

	if (n >= 0)
		return (ft_uintstr(dst, (uint64_t)n, base));
	if (base <= 1)
		return (ft_uintstr(dst, 0, base));
	if (base > 36)
		return (0);
	i = math_intlen(n, base);
	*dst++ = '-';
	dst += i - 1;
	while (n)
	{
		*dst-- = digits[-(n % base)];
		n /= base;
	}
	return ((uint8_t)(i + 1));
}
