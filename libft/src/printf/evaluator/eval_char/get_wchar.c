/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_wchar.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 19:44:15 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_wchar_st(wchar_t arg)
{
	char	*str;
	int		len;

	if (arg == 0)
		return (ft_strdup(PRNT_NULL));
	len = ft_wcharlen(arg);
	str = (char *)ft_memalloc(sizeof(char) * (len + 1));
	str[len] = 0;
	ft_wchar_in_str(arg, str, 0);
	return (str);
}

void			get_wchar(t_formatter *t, va_list lst)
{
	wchar_t	arg;
	char	*str;

	arg = va_arg(lst, wchar_t);
	str = get_wchar_st(arg);
	ft_memdel((void **)&(t->to_replace));
	t->to_replace = str;
}
