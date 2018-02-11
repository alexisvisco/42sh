/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/08 12:44:50 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/11 17:29:50 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# include "f_mem.h"
# include "f_heap.h"
# include "f_hashtable.h"
# include "f_trie.h"
# include "f_str.h"
# include "f_io.h"
# include "f_is.h"
# include "f_lib.h"
# include "f_lst.h"
# include "f_math.h"
# include "f_map.h"
# include "ft_printf.h"

# define SMART(type) __attribute__ ((__cleanup__(free_smart))) type
# define SMART_DEBUG(type) __attribute__ ((__cleanup__(free_debug))) type

#endif
