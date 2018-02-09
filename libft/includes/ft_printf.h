/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/09 13:02:03 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 14:45:07 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int			ft_dprintf(int fd, const char *format, ...);
int			ft_printf(const char *format, ...);
char		*ft_sprintf(const char *format, ...);
char		*core_printf(const char *format, va_list ap);
void		core_dprintf(int fd, const char *format, va_list ap);

void		percent_s(const char *format, va_list ap, char **to_write);
void		percent_di(const char *format, va_list ap, char **to_write);

#endif
