/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   word_is_path.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 18:27:05 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 11:13:55 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int	word_is_path(t_word_info *i)
{
	return ((ft_strstarts_with(i->current_word, '~') ||
	ft_strstarts_with(i->current_word, '/') ||
	ft_strstarts_with_str(i->current_word, "./")));
}
