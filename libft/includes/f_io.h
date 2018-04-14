/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   f_io.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 14:27:35 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _F_IO_H
# define _F_IO_H
# include <unistd.h>
# include <string.h>

# define BUFF_SIZE 32

typedef struct	s_gnl
{
	char			*text;
	char			*tempo;
	struct s_gnl	*next;
	int				fd;
}				t_gnl;

size_t			ft_putstr_fd(int fd, char const *s);
size_t			ft_putnstr_fd(int fd, char const *s, size_t n);
size_t			ft_putstr(char const *s);
size_t			ft_putnstr(char const *s, size_t n);

size_t			ft_putchar_fd(int fd, char c);
size_t			ft_putnchar_fd(int fd, char c, size_t n);
size_t			ft_putchar(char c);
size_t			ft_putnchar(char c, size_t n);

size_t			ft_putnum_fd(int fd, int64_t n, uint8_t base);
size_t			ft_putunum_fd(int fd, uint64_t n, uint8_t base);
size_t			ft_putfloat_fd(int fd, float n, int precision, uint8_t base);
size_t			ft_putunum(uint64_t n, uint8_t base);
size_t			ft_putnum(int64_t n, uint8_t base);
size_t			ft_putfloat(float n, int precision, uint8_t base);

t_gnl			**get_gnl(void);
void			free_gnl(void);
int				get_next_line(const int fd, char **line);

#endif
