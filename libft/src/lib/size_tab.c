/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   size_tab.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 20:59:33 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/11 17:29:50 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	size_tab(char **t)
{
	size_t i;

	i = 0;
	while (t[i])
		i++;
	return (i);
}
