/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:07:52 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/10 11:41:28 by aben-ham         ###   ########.fr       */
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

void	bonus_fract(t_prog *prog, t_complex p)
{
	t_complex		z;
	t_complex		t;
	int				iter;
	t_graph			*g;

	z.a = 0;
	z.b = 0;
	iter = -1;
	while (++iter < prog->depth)
	{
		t = z;
		z.a = t.a * t.a + t.a - t.b * t.b + p.a;
		z.b = 2 * t.a * t.b + t.b + p.b;
		if (z.a * z.a + z.b * z.b > 4)
			break ;
	}
	if (iter < prog->depth)
		trans_iter(z, &iter);
	g = &(prog->g);
	p.a = round((p.a / g->step - g->x_bound.a / g->step));
	p.b = round((p.b / g->step - g->y_bound.a / g->step));
	if (iter != prog->depth)
		mlx_img_pixel_put(prog, p.a, p.b, \
			prog->color_map[iter % 16] * prog->range_shift_color);
}
