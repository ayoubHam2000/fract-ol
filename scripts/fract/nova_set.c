/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nova_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:07:52 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/08 21:59:05 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	trans_iter(t_complex z, int *iter)
{
	long double	log_zn;
	long double	nu;

	log_zn = log(z.a * z.a + z.b * z.b) / 2;
	nu = log(log_zn / log(2)) / log(2);
	*iter = *iter + 1 - nu;
}

t_complex	c1(t_complex z)
{
	z.a -= 1;
	z.b -= 1;
	return (complex_mul(complex_mul(z, z), z));
}

t_complex	c2(t_complex z)
{
	t_complex	res;

	res = complex_mul(z, z);
	res.a *= 3;
	res.b *= 3;
	return (res);
}

void	nova_set(t_prog *prog, t_complex p)
{
	t_complex		z;
	t_complex		t;
	long double		div;
	int				iter;
	int				map[16];
	t_graph			*g;

	z.a = 0;
	z.b = 0;
	iter = 0;
	get_color(map);
	while (iter < STABLE)
	{
		z = complex_mul(complex_mul(z, z), z);
		z.a += p.a;
		z.b += p.b;
		if (z.a * z.a + z.b * z.b > 256)
			break ;
		iter++;
	}
	if (iter < STABLE)
		trans_iter(z, &iter);
	g = &(prog->g);
	p.a = round((p.a / g->step - g->x_bound.a / g->step));
	p.b = round((p.b / g->step - g->y_bound.a / g->step));
	printf("%Lf, %Lf\n", p.a, p.b);
	if (iter != STABLE)
		mlx_pixel_put(prog->mlx, prog->win, p.a, p.b, map[iter % 16]);
}

