/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/10 09:49:41 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/17 11:26:34 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_gnl	**get_gnl(void)
{
	static t_gnl *save = NULL;
	return (&save);
}

void	free_gnl(void)
{
	t_gnl	**gnl;
	t_gnl	*b;

	gnl = get_gnl();
	while (*gnl)
	{
		free((*gnl)->tempo);
		b = (*gnl);
		*gnl = (*gnl)->next;
		free(b);
	}
	free(*gnl);
	*gnl = NULL;
}