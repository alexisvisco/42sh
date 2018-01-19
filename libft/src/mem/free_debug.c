/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_debug.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 21:41:11 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/02 12:45:58 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	free_debug(void *ptr)
{
	void **real_ptr;

	real_ptr = (void **)ptr;
	free(*real_ptr);
	*real_ptr = NULL;
	ft_printf("Pointer %p is now free.\n", ptr);
}
