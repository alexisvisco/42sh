/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lex.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 12:54:48 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 17:43:53 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEX_H
# define LEX_H

# define FT_SEP		"&|;"
# define FT_REDIR	"><"
# define S			"(s + 1)"

typedef enum	e_tok_type
{
	COMMAND,
	ARG,
	IO_REDIR,
	SEP_OP,
	FD_FILE
}				t_tok_type;

typedef struct	s_token
{
	char		*value;
	t_tok_type	type;
	int			index;
}				t_token;


typedef struct	s_block
{
	int			start_tok;
	int			end_tok;
	int			isredir;
}				t_block;

char			*ft_specpy(char *s);
int				ft_counttoken(char *s);
t_token			**ft_splittokens(char *s, int nbtokens);

void			ft_lexall(t_token ***tokens, char *s);
char			*ft_removeq(char *s);

t_block			*extractblock(t_token **tokens);

void			analizeblock(t_block **blocks, t_token **tokens);
void			isred(t_block **block, t_token **tokens);

#endif