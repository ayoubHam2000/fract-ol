/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:03:16 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/08 16:26:48 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

typedef struct s_complex
{
	long double	a;
	long double	b;	
}	t_complex;

t_complex	complex_mul(t_complex z1, t_complex z2);
t_complex	complex_add(t_complex z1, t_complex z2);
t_complex	complex_sub(t_complex z1, t_complex z2);
t_complex	complex_div(t_complex z1, t_complex z2);
long double		complex_module(t_complex z);


void	complex_nadd(t_complex *z, long double a);
void	complex_nsub(t_complex *z, long double a);
void	complex_nmul(t_complex *z, long double a);
void	complex_ndiv(t_complex *z, long double a);

void	complex_print(t_complex z);

#endif
