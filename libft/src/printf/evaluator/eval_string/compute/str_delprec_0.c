/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   str_delprec_0.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 21:33:43 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_delprec_0(t_formatter *t)
{
	char *str;

	ft_memdel((void **)&(t->to_replace));
	str = ft_memalloc(sizeof(char) * 1);
	str[0] = 0;
	t->to_replace = str;
}
