/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   te_new_expr.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 14:57:55 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 14:57:55 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "expr.h"

t_expr	*new_expr(const int type, const t_expr *parameters[])
{
	const int arity = ARITY(type);
	const int psize = sizeof(void *) * arity;
	const int size = (sizeof(t_expr) - sizeof(void *)) + psize +
					 (IS_CLOSURE(type) ? sizeof(void *) : 0);
	t_expr *ret;

	ret = malloc(size);
	ft_memset(ret, 0, size);
	if (arity && parameters)
		ft_memcpy(ret->parameters, parameters, (size_t)psize);
	ret->type = type;
	ret->bound = 0;
	return (ret);
}