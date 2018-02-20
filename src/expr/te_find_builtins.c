/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   te_find_builtins.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 14:12:24 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 14:12:24 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "expr.h"


const	t_te_vars *find_builtin(const char *name, int len)
{
	int	imin;
	int	imax;
	int	i;
	int	c;

	imin = 0;
	imax = sizeof(functions) / sizeof(t_te_vars) - 2;
	while (imax >= imin)
	{
		i = (imin + ((imax - imin) / 2));
		c = ft_strncmp(name, functions[i].name, len);
		if (!c)
			c = '\0' - functions[i].name[len];
		if (c == 0)
			return (functions + i);
		else if (c > 0)
			imin = i + 1;
		else
			imax = i - 1;
	}
	return 0;
}