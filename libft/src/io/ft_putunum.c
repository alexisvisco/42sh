/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putunum.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 14:18:40 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putunum_fd(int fd, uint64_t n, uint8_t base)
{
	char	buf[128];

	return (write(fd, buf, (size_t)ft_uintstr(buf, n, base)));
}

size_t	ft_putunum(uint64_t n, uint8_t base)
{
	return (ft_putunum_fd(1, n, base));
}
