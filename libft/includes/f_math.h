/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   f_math.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 14:15:16 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/09 14:02:26 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _F_MATH_H
# define _F_MATH_H

int		math_abs(int i);
uint8_t	math_floatlen(float n, int precision, uint8_t base);
uint8_t	math_intlen(int64_t n, uint8_t base);
uint8_t	math_uintlen(uint64_t n, uint8_t base);
int		math_pgcd(int a, int b);
int		math_pow(int nb, int power);
int		math_round(double x);
int		math_sqrt(int nb);

#endif
