/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 10:02:28 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 14:25:39 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	call_formatter(char **s, int *i, t_formatter *fmt)
{
	char		*full_fmt;
	char		*str;

	str = *s;
	fmt->index = (*i);
	extract_full(fmt, (str + (*i)));
	full_fmt = fmt->full_formatter;
	extract_params(fmt, full_fmt);
}

void		evaluator_core(char **str, va_list lst)
{
	t_formatter fmt;
	int			i;
	char		*s;

	s = *str;
	i = 0;
	while (i < (int)ft_strlen(*str))
	{
		if ((*str)[i] == SYMBOL)
		{
			fmt = new_formatter();
			call_formatter(str, &i, &fmt);
			evaluator(str, &fmt, lst);
			i = fmt.index_replace_end;
			flush_formatter(&fmt);
		}
		else
			i++;
	}
}
