/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   te_find_lookup.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 14:08:01 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 14:08:01 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "expr.h"

const t_te_vars	*find_lookup(const t_state *s, const char *name, int len)
{
	int				iters;
	const t_te_vars	*var;

	if (!s->lookup)
		return (0);
	var = s->lookup;
	iters = s->lookup_len;
	while (iters)
	{
		if (strncmp(name, var->name, len) == 0 && var->name[len] == '\0')
			return (var);
		++var;
		--iters;
	}
	return (0);
}