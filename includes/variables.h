/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   variables.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 13:12:52 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 13:12:52 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#ifndef VARIABLES_H
# define VARIABLES_H

typedef enum	s_var_type{
	VAR_STRING,
	VAR_NUMBER
}				t_var_type;

typedef struct	s_variable
{
	char		symbol[32];
	t_var_type	var_type;
	void		*value;
}				t_var;

void			free_variable(void *var);
char			*v_value_to_str(t_var *v);
int				is_assignation_variable(char *str);
t_var_type get_type_of_assignation(char *str);
int				create_variable(char *assignation);
void			free_node_variable(void *var);

#endif
