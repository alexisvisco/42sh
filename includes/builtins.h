/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:45:07 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "shell.h"

typedef int(t_builtins_fun)(char **, t_shell *);

t_builtins_fun	*builtins(char *cmd);
t_builtins_fun	*builtins_env(char *cmd);
int				is_builtins_env(char *cmd);

t_hashtable		*get_builtins();
t_hashtable		*get_builtins_env(void);

int				b_pwd(char **args, t_shell *shell);
int				b_env(char **args, t_shell *shell);
int				b_echo(char **args, t_shell *shell);
int				b_history(char **args, t_shell *shell);
int				b_cd(char **args, t_shell *shell);
int				b_env_set(char **args, t_shell *shell);
int				b_env_unset(char **args, t_shell *shell);
int				b_clear(char **args, t_shell *shell);
int				b_exit(char **args, t_shell *shell);
int				b_search_binary(char **args, t_shell *shell);
int				b_set_last_history(char **args, t_shell *shell);
int				b_set_history_contain(char **args, t_shell *shell);
int				b_set_history_start(char **args, t_shell *shell);
int				b_set_history_from_n_last(char **args, t_shell *shell);
int				b_set_history_from_n(char **args, t_shell *shell);
int				b_expr_eval(char **args, t_shell *shell);
int				write_history(char **args);
int				clear_history(void);
int				del_history_at(char **args);
int				history_exe(char **args);
int				history_read(char **args);
int				history_help(void);
int				history_non_read(void);
int				show_history(t_shell *shell);
int				write_history(char **args);
int				append_history(char **args);
t_builtins_fun	*b_history_handler(char *cmd);
int				b_set_env_a(t_hashtable *envs, char *str, t_shell *shell);
void			b_set_env_b(t_hashtable *envs, char *key, char *val,
				t_shell *shell);
int				b_export(char **args, t_shell *sh);
int				b_unset(char **args, t_shell *sh);
int				b_typeof(char **args, t_shell *sh);
int				b_variables(char **args, t_shell *shell);

#endif
