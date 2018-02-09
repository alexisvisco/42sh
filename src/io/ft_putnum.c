/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnum.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 14:03:19 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 18:54:05 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnum_fd(int fd, int64_t n, uint8_t base)
{
	char	buf[128];

	return (write(fd, buf, (size_t)ft_intstr(buf, n, base)));
}

size_t	ft_putnum(int64_t n, uint8_t base)
{
	return (ft_putnum_fd(1, n, base));
}
