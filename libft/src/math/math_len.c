/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   math_len.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/16 11:05:16 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

uint8_t	math_floatlen(float n, int precision, uint8_t base)
{
	uint8_t	i;
	float	d;

	if ((int64_t)n == n)
		return (math_intlen((int64_t)n, base));
	i = math_intlen((int64_t)n, base);
	d = n - (int64_t)n;
	return (i + math_intlen((int64_t)(precision * d), 10));
}

uint8_t	math_intlen(int64_t n, uint8_t base)
{
	uint8_t	i;

	i = 1;
	while (n /= base)
		++i;
	return (i);
}

uint8_t	math_uintlen(uint64_t n, uint8_t base)
{
	uint8_t	i;

	i = 1;
	while (n /= base)
		++i;
	return (i);
}
