/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_tab.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 10:38:35 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Free an array of strings
*/

void	free_tab(char **table)
{
	int i;

	i = -1;
	if (table)
	{
		while (table[++i])
			ft_memdel((void **)&(table[i]));
		ft_memdel((void **)&table);
	}
}

void	free_3d_tab(char ***array)
{
	int i;
	int	j;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			j = 0;
			while (array[i][j])
				ft_memdel((void **)&(array[i][j++]));
			ft_memdel((void **)&(array[i]));
			i++;
		}
		ft_memdel((void **)&array);
	}
}
