/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   te_funcs_1.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 13:43:00 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 13:43:00 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "expr.h"

double	add(double a, double b)
{
	return (a + b);
}

double	fmodt(double a, double b)
{
	return ((int)a % (int)b);
}

double	sub(double a, double b)
{
	return (a - b);
}

double	mul(double a, double b)
{
	return (a * b);
}

double	divide(double a, double b)
{
	return (a / b);
}
