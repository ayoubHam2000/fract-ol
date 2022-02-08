/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:51:56 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/08 16:57:29 by aben-ham         ###   ########.fr       */
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

void	mandelbrot_set(t_prog *prog, t_complex p)
{
	t_complex		z;
	int				iter;
	long double		xtemp;
	int				map[16];
	t_graph			*g;

	z.a = 0;
	z.b = 0;
	iter = 0;
	get_color(map);
	while (z.a * z.a + z.b * z.b <= (1 << 16) && iter < STABLE)
	{
		xtemp = z.a * z.a - z.b * z.b + p.a;
		z.b = 2 * z.a * z.b + p.b;
		z.a = xtemp;
		iter++;
	}
	if (iter < STABLE)
		trans_iter(z, &iter);
	g = &(prog->g);
	p.a = round((p.a / g->step - g->x_bound.a / g->step));
	p.b = round((p.b / g->step - g->y_bound.a / g->step));
	if (iter != STABLE)
		mlx_pixel_put(prog->mlx, prog->win, p.a, p.b, map[iter % 16]);
}
