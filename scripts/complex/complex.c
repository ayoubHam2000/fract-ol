/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:04:25 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/07 15:24:49 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include <math.h>

# include <stdio.h>

t_complex	complex_mul(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.a = (z1.a * z2.a - z1.b * z2.b);
	res.b = (z1.a * z2.b + z1.b * z2.a);
	return (res);
}

t_complex	complex_add(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.a = z1.a + z2.a;
	res.b = z1.b + z2.b;
	return (res);
}

t_complex	complex_sub(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.a = z1.a - z2.a;
	res.b = z1.b - z2.b;
	return (res);
}

t_complex	complex_div(t_complex z1, t_complex z2)
{
	t_complex	res;
	double	b;

	b = z2.a * z2.a + z2.b * z2.b;
	if (b == 0)
	{
		res.a = 0;
		res.b = 0;
	}
	res.a = (z1.a * z2.a + z1.b * z2.b) / b;
	res.b = (z1.b * z2.a - z2.b * z1.a) / b;
	return (res);
}

double	complex_module(t_complex z)
{
	return (sqrt(z.a * z.a + z.b * z.b));
}

void	complex_print(t_complex z)
{
	printf("(%f, %f)\n", z.a, z.b);
}
