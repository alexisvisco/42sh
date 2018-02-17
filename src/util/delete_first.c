/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   delete_first.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 11:31:38 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/17 11:26:33 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	delete_first_element(char ***s)
{
	char	**ret;
	int		i;
	int		end;

	end = 0;
	while ((*s)[end])
		end++;
	ret = malloc(sizeof(char *) * end);
	ret[end - 1] = NULL;
	i = 1;
	while (i < end)
	{
		ret[i - 1] = ft_strdup((*s)[i]);
		i++;
	}
	i = 0;
	while ((*s)[i])
	{
		free((*s)[i]);
		i++;
	}
	free((*s));
	(*s) = ret;
	i = 0;
}
