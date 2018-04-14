/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   extractor.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 20:20:55 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	extract_params(t_formatter *fmt, char *full)
{
	if (!full)
		return ;
	while (*full)
	{
		if (ft_strchr(FLAGS, *full))
			extract_flags(fmt, &full);
		else if (ft_isdigit(*full) || *full == '*')
			extract_width(fmt, &full);
		else if (*full == '.')
			extract_precision(fmt, &full);
		else if (ft_strchr(LENGTH, *full))
			extract_length(fmt, &full);
		else
			full++;
	}
}
