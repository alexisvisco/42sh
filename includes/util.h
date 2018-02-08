/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/21 15:53:14 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 14:46:31 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <libft.h>

void	*ft_realloc(void *ptr, size_t size);
char	*ft_char_to_str(char c);
void	free_tab(char **table);
void	free_3d_tab(char ***array);
char	**env_to_array(void);
size_t	env_size(void);
void	delete_first_element(char ***s);
void	ft_copy_str(char *dest, char *src);
int		ft_levenshtein(char *s1, char *s2, size_t s1len, size_t s2len);

int				nb_equal_char(char *s1, char *s2);

#endif
