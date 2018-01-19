/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putfloat.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 14:21:48 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/02 12:53:55 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putfloat_fd(int fd, float n, int precision, uint8_t base)
{
	char	buf[128];

	return (write(fd, buf, (size_t)ft_floatstr(buf, n, precision, base)));
}

size_t	ft_putfloat(float n, int precision, uint8_t base)
{
	return (ft_putfloat_fd(1, n, precision, base));
}
