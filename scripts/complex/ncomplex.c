/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncomplex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:58:23 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/08 16:24:54 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

void	complex_nadd(t_complex *z, long double a)
{
	z->a += a;
	z->b += a;
}


void	complex_nsub(t_complex *z, long double a)
{
	z->a -= a;
	z->b -= a;
}

void	complex_nmul(t_complex *z, long double a)
{
	z->a *= a;
	z->b *= a;
}

void	complex_ndiv(t_complex *z, long double a)
{
	if (!a)
		return ;
	z->a /= a;
	z->b /= a;
}
