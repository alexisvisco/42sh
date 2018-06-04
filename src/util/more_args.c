/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   more_args.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/25 17:30:06 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/25 17:30:06 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include "util.h"

int		has_arg(int args, int query)
{
	return (args & query);
}

void	i_want_to_print(int args)
{
	if (has_arg(args, BOAT))
		printf("I want to travel the world with a boat\n");
	if (has_arg(args, CAR))
		printf("I want to buy a car\n");
	if (has_arg(args, PLANE))
		printf("I want to fly with a plane around the 101 campus\n");
	if (has_arg(args, MOTORBIKE))
		printf("I just like simplicity of motorbike\n");
	if (has_arg(args, TRAIN))
		printf("An other example with train...\n");
	if (args == 0)
		printf("No arguments\n");
}
