/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:45:07 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 20:59:03 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdlib.h>

typedef int(t_builtins_fun)(char **, t_hashtable *);

t_builtins_fun  *builtins(char *cmd);
t_hashtable     *get_builtins();
int             b_pwd(char **args, t_hashtable *envs);
int             b_env(char **args, t_hashtable *envs);
int             b_env_set(char **args, t_hashtable *envs);
int             b_env_unset(char **args, t_hashtable *envs);
int             b_clear(char **args, t_hashtable *envs);

#endif
