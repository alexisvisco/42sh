/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_printer_preset.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 09:58:56 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/16 10:04:34 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	lst_print_str(t_list *l)
{
	ft_putstr((char *)l->content);
}

void	lst_print_int(t_list *l)
{
	ft_putnum((int)l->content, 10);
}

void	lst_print_int_bin(t_list *l)
{
	ft_putnum((int)l->content, 2);
}

void	lst_print_int_hex(t_list *l)
{
	ft_putnum((int)l->content, 16);
}

void	lst_print_bool(t_list *l)
{
	ft_putstr((int)l->content == 0 ? "false" : "true");
}
