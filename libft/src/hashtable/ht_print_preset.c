/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ht_print_preset.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 18:11:03 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ht_print_str(t_node *a)
{
	ft_printf("%s = %s", a->key, (char *)a->value);
}

void	ht_print_int(t_node *a)
{
	ft_printf("%s = %d", a->key, *(int *)a->value);
}

void	ht_print_int_hex(t_node *a)
{
	ft_printf("%s = %#x", a->key, *(int *)a->value);
}

void	ht_print_bool(t_node *a)
{
	ft_printf("%s = %s", a->key, *(int *)a->value == 0 ? "false" : "true");
}
