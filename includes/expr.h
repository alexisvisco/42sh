/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   expr.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 11:15:54 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 11:15:54 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef EXPR_H
# define EXPR_H

typedef double		(*t_fun2)(double, double);

typedef struct		s_expr
{
	int				type;
	double			value;
	const double	*bound;
	const void		*function;
	void			*parameters[1];
}					t_expr;

enum {
	TE_VARIABLE = 0,
	TE_FUNCTION0 = 8,
	TE_FUNCTION1,
	TE_FUNCTION2,
	TE_FUNCTION3,
	TE_FUNCTION4,
	TE_FUNCTION5,
	TE_FUNCTION6,
	TE_FUNCTION7,
	TE_CLOSURE0 = 16,
	TE_CLOSURE1,
	TE_CLOSURE2,
	TE_CLOSURE3,
	TE_CLOSURE4,
	TE_CLOSURE5,
	TE_CLOSURE6,
	TE_CLOSURE7,
	TE_FLAG_PURE = 32
};

typedef struct		s_te_variable {
	const char		*name;
	const void		*address;
	int				type;
	void			*context;
}					t_te_vars;

enum
{
	TOK_NULL = TE_CLOSURE7 + 1,
	TOK_ERROR,
	TOK_END,
	TOK_SEP,
	TOK_OPEN,
	TOK_CLOSE,
	TOK_NUMBER,
	TOK_VARIABLE,
	TOK_INFIX
};

enum
{
	TE_CONSTANT = 1
};

typedef struct		s_state
{
	const char		*start;
	const char		*next;
	int				type;
	double			value;
	const double	*bound;
	const void		*function;
	void			*context;
	const t_te_vars *lookup;
	int				lookup_len;
}					t_state;

# define TYPE_MASK(TYPE) ((TYPE)&0x0000001F)
# define IS_PURE(TYPE) (((TYPE) & TE_FLAG_PURE) != 0)
# define IS_FUNCTION(TYPE) (((TYPE) & TE_FUNCTION0) != 0)
# define IS_CLOSURE(TYPE) (((TYPE) & TE_CLOSURE0) != 0)
# define ORC (TE_FUNCTION0 | TE_CLOSURE0)
# define ARITY(TYPE) (((TYPE) & ORC) ? ((TYPE) & 0x00000007) : 0)
# define NEW_EXPR(type, ...) new_expr((type), (const t_expr*[]){__VA_ARGS__})
# define TE_FUN(...) ((double(*)(__VA_ARGS__))n->function)
# define M(e) te_eval(n->parameters[e])
# ifndef NAN
#  define NAN (0.0/0.0)
# endif

# ifndef INFINITY
#  define INFINITY (1.0/0.0)
# endif

double				te_interp(const char *expression, int *error);
t_expr				*te_compile(const char *expression, const t_te_vars
								*variables, int var_count, int *error);
double				te_eval(const t_expr *n);
void				te_free(t_expr *n);
const t_te_vars		*find_builtin(const char *name, int len);
const t_te_vars		*find_lookup(const t_state *s, const char *name,
					int len);
t_expr				*new_expr(const int type, const t_expr *parameters[]);
void				te_free_parameters(t_expr *n);
void				te_free(t_expr *n);
double				pi();
double				e();
double				fac(double a);
double				ncr(double n, double r);
double				fmodt(double n, double r);
double				npr(double n, double r);
double				add(double a, double b);
double				sub(double a, double b);
double				mul(double a, double b);
double				divide(double a, double b);
double				negate(double a);
double				comma(double a, double b);
void				next_token(t_state *s);
t_expr				*base(t_state *s);
t_expr				*power(t_state *s);
t_expr				*factor(t_state *s);
t_expr				*term(t_state *s);
t_expr				*expr(t_state *s);
t_expr				*list(t_state *s);
double				te_eval(const t_expr *n);
void				optimize(t_expr *n);
t_expr				*te_clos0(t_state *s, t_expr *ret);
t_expr				*te_clos1(const t_state *s, t_expr *ret);
t_expr				*te_clos7(t_state *s, t_expr *ret, int a);

#endif
