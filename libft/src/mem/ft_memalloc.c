/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/10 18:49:29 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "f_colors.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	str = malloc(sizeof(void*) * size);
	if (str == NULL)
	{
		ft_putstr(CRITICAL_RED);
		ft_putstr(WHITE);
		ft_putstr("WARNING: the program does not behave correctly.");
		ft_putstr(" The malloc function returned null. The program will try");
		ft_putstr(" to exit.\nWe are absolutely not responsible for what can");
		ft_putstr(" follow. We are in the 21st century.\n");
		ft_putstr(RESET_ALL);
		exit(1);
	}
	ft_bzero(str, sizeof(void *) * size);
	return (str);
}
