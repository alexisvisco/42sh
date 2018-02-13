/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_repall.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 12:58:31 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 14:09:25 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char	*ft_repall(char *target, char *by, char *src)
{
	char *tmp;
	char *full;

	full = ft_strdup(src);
	while (!ft_strequ(target, by) && ft_strstr(full, target))
	{
		tmp = full;
		full = ft_strrep_first_aft(target, by, full, 0);
		if (!full)
			full = tmp;
		else
			free(tmp);
	}
	return (full);
}
