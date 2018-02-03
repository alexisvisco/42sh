/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_tab.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 10:38:35 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 15:18:44 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	free_tab(char **table)
{
	int i;

	i = -1;
	if (table)
	{
		while (table[++i])
			free(table[i]);
		free(table);
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
				free(array[i][j++]);
			free(array[i]);
			i++;
		}
		free(array);
	}
}
