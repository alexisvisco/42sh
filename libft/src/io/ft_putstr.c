/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 13:41:36 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr_fd(int fd, char const *s)
{
	return (write(fd, s, ft_strlen(s)));
}

size_t	ft_putnstr_fd(int fd, char const *s, size_t n)
{
	size_t r;

	r = 0;
	while (n > 0)
	{
		r += (write(fd, s, ft_strlen(s)));
		n--;
	}
	return (r);
}

size_t	ft_putstr(char const *s)
{
	return (ft_putstr_fd(1, s));
}

size_t	ft_putnstr(char const *s, size_t n)
{
	return (ft_putnstr_fd(1, s, n));
}
