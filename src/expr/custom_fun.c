/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   custom_atoi.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/26 11:40:25 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/26 11:40:25 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <expr.h>

int	custom_atoi(char **str)
{
	int nbr;

	nbr = 0;
	while (**str >= '0' && **str <= '9')
	{
		nbr = nbr * 10 + (**str - '0');
		(*str)++;
	}
	return (nbr);
}

int	can_exec(t_res *res, int number)
{
	if (number == 0)
		res->error = ft_strdup("Invalid operation.");
	return (number != 0);
}

int	valid_expr(char *expr)
{
	while (*expr)
	{
		if (!ALLOWEDS_CHARS(*expr))
			return (0);
		expr++;
	}
	return (1);
}
