/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnum.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 14:03:19 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/02 12:53:48 by aviscogl    ###    #+. /#+    ###.fr     */
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
