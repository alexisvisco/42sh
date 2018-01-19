/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 13:02:54 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/19 19:41:47 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "shell.h"

void	test(t_tok_type type)
{
	ft_printf("tok type = %i\n", type);
}

char	*ft_specpy(char *s, char c)
{
	char	*ret;
	int		i;
	
	ret = ft_strnew(ft_strlen(s) - 2);
	s++;
	i = 0;
	while (*s)
	{
		if (*s == '\\')
		{
			ret[i++] = *(s++);
			ret[i++] = *(s++);
		}
		if (*s == c && ((*(s + 1) && *(s + 1) == ' ') || (!*(s + 1))))
			break;
		else if (*s == c)
			ret[i++] = *(s++);
		else if (*s != '\\')
			ret[i++] = *(s++);
	}
	return (ret);
}

int		main(int args, char **argv)
{
	char	*str;
	char	*s = ft_strdup(argv[1]);
	
	ft_printf("La string : %s\n", s);
	str = ft_specpy(s, '\"');
	printf("a%sb\n", str);
}