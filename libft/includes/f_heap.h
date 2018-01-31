/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   f_heap.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 14:15:22 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 12:59:20 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _F_HEAP_H
# define _F_HEAP_H
# include <string.h>
# include <stdlib.h>

typedef struct		s_heap
{
	void			**list;
	size_t			size;
	size_t			next_insert;
	int64_t			last_remove;
	size_t			elements;
	void			(*free_func)(void *);
}					t_heap;

void				heap_add(t_heap *heap, void *content);
int64_t				heap_get_whole(t_heap *heap);
void				*heap_get(t_heap *heap, size_t n);
void				heap_growth(t_heap *hp);
t_heap				*heap_new(size_t default_size);
void				heap_print(t_heap *h, void (*print_function)(void*));
void				*heap_del(t_heap *heap, size_t n);
void				heap_free(t_heap *h);

void				heap_print_str(void *v);
void				heap_print_int(void *v);
void				heap_print_int_bin(void *v);
void				heap_print_int_hex(void *v);
void				heap_print_bool(void *v);

#endif
