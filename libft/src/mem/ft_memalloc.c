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

unsigned int rand_interval(unsigned int min, unsigned int max)
{
	unsigned int r;
	const unsigned int range = 1 + max - min;
	const unsigned int buckets = RAND_MAX / range;
	const unsigned int limit = buckets * range;

	do
	{
		r = rand();
	} while (r >= limit);

	return min + (r / buckets);
}

void	*ft_memalloc(size_t size)
{
	void	*str;

	str = malloc(sizeof(void*) * size);
	if (str == NULL)
	{
		ft_putstr(CRITICAL_RED WHITE"WARNING: the program does not behave correctly. The"
		" malloc function returned null. The program will"
		" try to exit.\nWe are absolutely not responsible for what can follow. We"
		" are in the 21st century.\n"RESET_ALL);
		exit(1);
		return (NULL);
	}
	ft_bzero(str, sizeof(void *) * size);
	return (str);
}
