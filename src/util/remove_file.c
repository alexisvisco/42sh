/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   remove_file.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 15:53:08 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/17 11:26:33 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	tab_del_from_to(char ***t, int from, int to)
{
	char	**res_tab;
	int		i;
	int		j;

	res_tab = malloc(sizeof(char *) * (size_tab(*t) - (to - from) + 1));
	j = 0;
	i = 0;
	while ((*t)[i])
	{
		if (i >= from && i <= to)
			;
		else
			res_tab[j++] = ft_strdup((*t)[i]);
		i++;
	}
	res_tab[j] = NULL;
	free_tab(*t);
	*t = res_tab;
}
