/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_str.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 10:23:00 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 10:58:50 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

char	*get_next_str(char *from, char *full)
{
	const size_t	len = ft_strlen(full);
	int				i;
	int				prev;

	i = -1;
	while (++i < len)
	{
		if ((!from[i]) || (from[i] != full[i]))
			break ;
	}
	return (ft_strsub(full, i, len - i));
}
