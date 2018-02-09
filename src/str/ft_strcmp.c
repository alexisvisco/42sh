/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/10/20 20:15:33 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/25 10:48:42 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	if (*s1 == '\0' || *s2 == '\0')
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	while (*s1++ == *s2++ && !(*s1 == '\0' && *s2 == '\0'))
		;
	return (*((unsigned char *)s1 - 1) - *((unsigned char *)s2 - 1));
}
