/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/08 15:39:27 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 13:51:59 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strcpy(char *d, const char *s)
{
	char *saved;

	saved = d;
	while (*s)
		*d++ = *s++;
	*d = 0;
	return (saved);
}
