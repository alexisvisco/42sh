/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   validate_expr.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/03 21:54:15 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/03 21:54:15 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

#define CANT_START "*/+%)<>|^~!="
#define CANT_END "*/+-%(<>|^~!="
#define AUTORIZED "*/+-%()<>|^~!="
#define INV(r, e) ft_strchr(CANT_START, (r)[0]) || ft_strchr(CANT_END, (r)[e])

static int		is_an_operator(char *str, int *it)
{
	int			len;
	int			i;
	const char	*ops[] = {
		"*", "/", "+", "-", "%",
		"^", "|", "~", "<", ">",
		">=", "<=", "==", "!=",
		"<<", ">>", NULL};

	i = 16;
	while (i-- > 0)
	{
		len = (int)ft_strlen(ops[i]);
		if (len == 2 && str[*it] == ops[i][0] && str[(*it) + 1] == ops[i][1])
		{
			*it += 1;
			return (2);
		}
		else if (str[*it] == ops[i][0])
			return (1);
	}
	return (0);
}

static int		can_next(char *str, int *unclose_par, int *i)
{
	int		op_len;

	if (str[(*i)] == '(')
		(*unclose_par)++;
	else if (str[(*i)] == ')')
		(*unclose_par)--;
	if ((op_len = is_an_operator(str, i)) != 0)
	{
		if (str[(*i) - op_len] == '(' && ft_strchr(CANT_START, str[(*i) -
		(op_len == 2 ? 1 : 0)]))
			return (0);
		if (str[(*i) + 1] == ')' && !ft_isdigit(str[(*i)]))
			return (0);
	}
	else if (!ft_strchr(AUTORIZED, str[*i]) && !ft_isdigit(str[*i]))
		return (0);
	return (1);
}

int 			validate_simple_exp(char *expr)
{
	char	*rep;
	int		len;
	int 	unclose_par;
	int 	i;


	rep = ft_repall(" ", "", expr);
	len = (int)ft_strlen(rep);
	i = -1;
	if (INV(rep, len - 1))
	{
		free(rep);
		return (0);
	}
	unclose_par = 0;
	while (rep[++i])
	{
		if (!can_next(rep, &unclose_par, &i))
		{
			free(rep);
			return (0);
		}
	}
	free(rep);
	return (unclose_par == 0);
}

