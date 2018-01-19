/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putchar.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 13:48:35 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/02 12:51:34 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putchar_fd(int fd, char c)
{
	return (write(fd, (uint8_t *)(&c), sizeof(char)));
}

size_t	ft_putnchar_fd(int fd, char c, size_t n)
{
	char buf[(n * sizeof(char)) + 1];

	ft_memset(buf, c, n);
	buf[n] = '\0';
	return (ft_putstr_fd(fd, buf));
}

size_t	ft_putchar(char c)
{
	return (ft_putchar_fd(1, c));
}

size_t	ft_putnchar(char c, size_t n)
{
	return (ft_putnchar_fd(1, c, n));
}
