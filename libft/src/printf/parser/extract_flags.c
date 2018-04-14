/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   extract_flags.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 13:03:49 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	extract_flags(t_formatter *fmt, char **str)
{
	if (ft_strchr(FLAGS, **str) && !ft_strchr(fmt->flags, **str))
		ft_strcat_ch(fmt->flags, **str);
	(*str)++;
}
