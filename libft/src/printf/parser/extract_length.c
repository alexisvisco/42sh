/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   extract_length.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 13:18:51 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/02 13:22:45 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

#define IS_DL(str, ch) ((*str)[0] == ch && (*str)[1] && (*str)[1] == ch)

void	extract_length(t_formatter *fmt, char **str)
{
	if (IS_DL(str, 'h') || IS_DL(str, 'l'))
	{
		ft_strcpy(fmt->length, (*str[0] == 'h' ? "hh" : "ll"));
		(*str) += 2;
	}
	else if (ft_strchr(LENGTH, **str))
	{
		fmt->length[0] = **str;
		fmt->length[1] = 0;
		(*str)++;
	}
}
