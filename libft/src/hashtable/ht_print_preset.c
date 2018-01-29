/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ht_print_preset.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 18:11:03 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 18:13:51 by aviscogl    ###    #+. /#+    ###.fr     */
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
