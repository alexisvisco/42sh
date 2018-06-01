/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_ext.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/10 09:49:41 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 10:15:18 by aviscogl    ###    #+. /#+    ###.fr     */
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
		ft_memdel((void **)&((*gnl)->tempo));
		b = (*gnl);
		*gnl = (*gnl)->next;
		ft_memdel((void **)&b);
	}
	ft_memdel((void **)&(*gnl));
	*gnl = NULL;
}
