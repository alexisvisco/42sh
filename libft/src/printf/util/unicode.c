/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   unicode.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/24 15:12:16 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/03 16:18:00 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_wcharlen(wchar_t wchar)
{
	if (wchar <= 0x7f)
		return (1);
	else if (wchar <= 0x7ff)
		return (2);
	else if (wchar <= 0xffff)
		return (3);
	else
		return (4);
}

size_t		ft_byte_wstrlen(wchar_t *ws)
{
	size_t	len;

	len = 0;
	if (!ws)
		return (0);
	while (*ws)
		len += ft_wcharlen(*ws++);
	return (len);
}

size_t		ft_wstrlen(wchar_t *ws)
{
	size_t	len;

	len = 0;
	if (!ws)
		return (0);
	while (*(ws++))
		len++;
	return (len);
}

wchar_t		*ft_wstrsubpf(wchar_t *ws, int end)
{
	wchar_t	*new;
	int		i;
	int		count;

	if (end < 0)
		return (NULL);
	count = 0;
	i = 0;
	new = (wchar_t *)malloc(sizeof(wchar_t) * (end + 1));
	while (*ws)
	{
		count += ft_wcharlen(*ws);
		if (count <= end)
			new[i++] = *ws;
		ws++;
	}
	new[i] = 0;
	return (new);
}
