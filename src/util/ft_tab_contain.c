/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tab_contain.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 16:59:30 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 15:40:03 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		ft_tab_contain(const char **tabi, char *src)
{
	while (*tabi)
	{
		if (ft_strequ(*tabi, src))
			return (1);
		tabi++;
	}
	return (0);
}
