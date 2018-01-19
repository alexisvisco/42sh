/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   extract_full.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 12:52:59 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 11:05:33 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	if_null(t_formatter *fmt)
{
	if (fmt->type == 0)
	{
		fmt->type = 's';
		fmt->full_formatter = ft_strdup("%");
	}
}

int			extract_full(t_formatter *fmt, char *s)
{
	int i;

	i = 1;
	while (s[i])
	{
		if (ft_strchr(C_S, s[i]))
		{
			fmt->type = s[i];
			fmt->full_formatter = ft_strsub(s, 0, i + 1);
			break ;
		}
		else if (!ft_strchr(BEFORE_C_S, s[i]))
		{
			fmt->type = 'c';
			fmt->non_spec_arg = s[i];
			fmt->full_formatter = ft_strsub(s, 0, i + 1);
			break ;
		}
		i++;
	}
	if_null(fmt);
	return (i + 1);
}
