/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util_command.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 09:59:36 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 10:01:49 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Get the first arguement that is not an option (don't start with '-')
*/

char	*get_first_arg(char **a)
{
	a++;
	while (*a)
	{
		if (!ft_strstarts_with(*a, '-'))
			return (*a);
		a++;
	}
	return (NULL);
}

/*
** Parse all arguments specified in args for a command
*/

void	parse_arguments(char **args, char *ar, const char *allowed)
{
	int i;

	args++;
	while (*args)
	{
		if (ft_strstarts_with(*args, '-'))
		{
			i = 0;
			while ((*args)[i])
			{
				if (ft_strchr(ar, (*args)[i]) == NULL &&
					ft_strchr(allowed, (*args)[i]))
					ft_strcat_ch(ar, (*args)[i]);
				i++;
			}
		}
		args++;
	}
}
