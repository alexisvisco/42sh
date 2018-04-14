/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_smart.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 15:40:19 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

void	free_smart(void *ptr)
{
	void **real_ptr;

	real_ptr = (void **)ptr;
	free(*real_ptr);
	*real_ptr = NULL;
}
