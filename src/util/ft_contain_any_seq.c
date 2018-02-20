/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_contain_any_seq.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/17 13:19:33 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 10:13:20 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int	ft_contain_any_seq(char *str, const char *seq)
{
	while (*seq)
	{
		if (ft_strchr(str, *seq))
			return (1);
		seq++;
	}
	return (0);
}
