/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 12:36:40 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "libft.h"
# include "lex.h"
# include "editor.h"
# include "exec.h"

void			*ft_realloc(void *ptr, size_t size);
char			*ft_char_to_str(char c);

void			free_tab(char **table);
void			free_3d_tab(char ***array);

char			**env_to_array(t_hashtable *envx);
size_t			env_size(t_hashtable *envx);

void			delete_first_element(char ***s);
void			tab_del_from_to(char ***t, int from, int to);
void			free_toks(t_token **tokens);

void			ft_copy_str(char *dest, char *src);
int				ft_levenshtein(char *s1, char *s2, size_t s1len, size_t s2len);
int				ft_tab_contain(const char **tabi, char *src);
int				nb_equal_char(char *s1, char *s2);

t_heap			*ask_line(char *prompt, int nl,
					int (*is_end)(char *cmp, char *line), char *cmp);
char			*heap_to_str(t_heap *h, int nl);
char			*heap_to_str_rm_one(t_heap *h);
int				odd_quote(char *quote, char *line);
char			which_quote(char *s);
char			*multi_line_prompt(char *line, int free_line);
void			odd_quote_prompt(t_token ***tokens, char *s);
char			*replace_env_variables(char *str, int free_str);
char			*ft_repall(char *target, char *by, char *src);
int				ft_contain_any_seq(char *str, const char *seq);
char			*get_first_arg(char **a);
void			parse_arguments(char **args, char *ar, const char *allowed);
int				*vint(int x);
t_hashtable		*clone_hashtable(t_hashtable *t);
char			**strsplit_first(char *str, const char *separator);
void			free_node(t_node **d);

int				is_directory(const char *path);

#endif
