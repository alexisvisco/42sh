/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ht_print_preset.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 18:11:03 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 18:52:54 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ht_print_str(t_node *a)
{
	ft_putstr(a->key);
	ft_putstr(" = ");
	ft_putstr((char *)a->value);
}

void	ht_print_int(t_node *a)
{
	ft_putstr(a->key);
	ft_putstr(" = ");
	ft_putnum((int64_t)a->value, 10);
}

void	ht_print_bool(t_node *a)
{
	ft_putstr(a->key);
	ft_putstr(" = ");
	ft_putstr(*(int *)a->value == 0 ? "false" : "true");
}
