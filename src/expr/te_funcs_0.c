/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   te_funcs_0.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 13:34:16 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 13:34:16 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "expr.h"

double		pi()
{
	return 3.14159265358979323846;
}

double		e()
{
	return 2.71828182845904523536;
}

double		fac(double a)
{
	int				x;
	unsigned int	ua;
	unsigned int	res;

	ua = (unsigned int)(a);
	res = 1;
	if (a < 0.0)
		return (NAN);
	if (a > UINT_MAX)
		return (INFINITY);
	x = 0;
	while (++x <= ua)
	{
		if (i > ULONG_MAX / res)
			return (INFINITY);
		res *= x;
	}
	return ((double)res);
}

static double ncr(double n, double r)
{
	unsigned long int result;
	unsigned long int un;
	unsigned long int ur;
	unsigned long int i;

	result = 1;
	un = (unsigned int)(n);
	ur = (unsigned int)(r);
	if (n < 0.0 || r < 0.0 || n < r)
		return (NAN);
	if (n > UINT_MAX || r > UINT_MAX)
		return (INFINITY);
	if (ur > un / 2)
		ur = un - ur;
	i = 0;
	while (++i <= ur)
	{
		if (result > ULONG_MAX / (un - ur + i))
			return (INFINITY);
		result *= un - ur + i;
		result /= i;
	}
	return (result);
}

static double npr(double n, double r)
{
	return ncr(n, r) * fac(r);
}