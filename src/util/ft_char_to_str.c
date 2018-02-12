/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_char_to_str.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 20:43:03 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 13:51:59 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Get a string from a char
*/

char	*ft_char_to_str(char c)
{
	char *s;

	s = malloc(sizeof(char) * 2);
	s[0] = c;
	s[1] = '\0';
	return (s);
}
