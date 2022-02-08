/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:24:08 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/08 15:32:58 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	trans_iter(t_complex z, int *iter)
{
	double	log_zn;
	double	nu;

	log_zn = log(z.a * z.a + z.b * z.b) / 2;
	nu = log(log_zn / log(2)) / log(2);
	*iter = *iter + 1 - nu;
}

void	julia_set(t_prog *prog, t_complex p)
{
	t_complex	z;
	int			iter;
	double		xtemp;
	int			map[16];
	t_graph		*g;

	z = p;
	iter = 0;
	get_color(map);
	while (z.a * z.a + z.b * z.b <= (1 << 16) && iter < STABLE)
	{
		xtemp = z.a * z.a - z.b * z.b + 0.7885 * (cos(prog->julia_const));
		z.b = 2 * z.a * z.b + 0.7885 * (sin(prog->julia_const));
		z.a = xtemp;
		iter++;
	}
	if (iter < STABLE)
		trans_iter(z, &iter);
	g = &(prog->g);
	p.a = round((p.a / g->step - g->x_bound.a / g->step));
	p.b = round((p.b / g->step - g->y_bound.a / g->step));
	mlx_pixel_put(prog->mlx, prog->win, p.a, p.b, map[iter % 16]);
}