/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_char.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 19:40:35 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 13:51:49 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_char_st(char c)
{
	char *str;

	if (c == 0)
		return (ft_strdup(PRNT_NULL));
	str = malloc(sizeof(char) * (2));
	str[1] = 0;
	str[0] = c;
	return (str);
}

static void		char_pad_null(int w, t_formatter *t)
{
	char *str;
	char *strn;

	str = ft_str_repeatm(ft_strchr(t->flags, '0') ? '0' : ' ', w - 1);
	strn = ft_strappend_at(ft_strchr(t->flags, '-') ? ft_strlen(t->to_replace)
	: 0, t->to_replace, str);
	free(str);
	free(t->to_replace);
	t->to_replace = strn;
}

void			get_char(t_formatter *t, va_list lst)
{
	char	arg;
	char	*str;

	if (ft_strchr(t->length, 'l') || t->type == 'C')
		return (get_wchar(t, lst));
	if (t->non_spec_arg == 0)
		arg = va_arg(lst, int);
	else
		arg = t->non_spec_arg;
	free(t->to_replace);
	str = get_char_st(arg);
	t->to_replace = str;
	if (arg)
		str_compute(t);
	else if (t->width > 1)
		char_pad_null(t->width, t);
}
