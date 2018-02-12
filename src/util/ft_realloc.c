/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/21 09:56:18 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 09:27:52 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** ptr: This is the pointer to a memory block previously allocated with malloc,
** calloc or realloc to be reallocated. If this is NULL, a new block is
** allocated.
** and a pointer to it is returned by the function
**
** size: This is the new size for the memory block, in bytes. If it is 0 and
** ptr points to an existing block of memory, the memory block pointed by ptr is
** deallocated and a NULL pointer is returned.
**
** This function returns a pointer to the newly allocated memory, or NULL if the
** request fails
*/

void	*ft_realloc(void *ptr, size_t size)
{
	char	*newptr;

	if (!size && ptr)
	{
		if (!(newptr = (char *)malloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		return (newptr);
	}
	if (!(newptr = (char *)malloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(newptr, ptr, size);
		ft_memdel(&ptr);
	}
	return (newptr);
}
