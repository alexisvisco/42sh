/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lex.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 12:54:48 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/19 17:22:19 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEX_H
# define LEX_H

/*
**	Error :		return (-1) : chaine vide.
**
**
**
*/

typedef enum	e_tok_type
{
				PIPE,
				COMMAND,
				ARG,
				IO_REDIRECT,
				SEPARATOR_OP,
				FD
}				t_tok_type;

typedef struct	s_token
{
	char 		*value;
	t_tok_type	type;
}				t_token;

#endif