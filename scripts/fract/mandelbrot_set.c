/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:51:56 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/07 20:39:49 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	setRgb(int r, int g, int b)
{
	int	res;

	res = b;
	res |= g << 8;
	res |= r << 8;
	return (res);
}

static void	get_color(int map[])
{
	map[0] = setRgb(66, 30, 15);
    map[1] = setRgb(25, 7, 26);
    map[2] = setRgb(9, 1, 47);
    map[3] = setRgb(4, 4, 73);
    map[4] = setRgb(0, 7, 100);
    map[5] = setRgb(12, 44, 138);
    map[6] = setRgb(24, 82, 177);
    map[7] = setRgb(57, 125, 209);
    map[8] = setRgb(134, 181, 229);
    map[9] = setRgb(211, 236, 248);
    map[10] = setRgb(241, 233, 191);
    map[11] = setRgb(248, 201, 95);
    map[12] = setRgb(255, 170, 0);
    map[13] = setRgb(204, 128, 0);
    map[14] = setRgb(153, 87, 0);
    map[15] = setRgb(106, 52, 3);
}
/*
void	mandelbrot_set(t_prog *prog, t_complex c)
{
	t_graph	*g;

	g = &(prog->g);
	if (c.a > -0.5 && c.a < 0.5 && c.b > -0.5 && c.b < 0.5)
	{
		c.a = round((c.a / g->step - g->x_bound.a / g->step));
		c.b = round((c.b / g->step - g->y_bound.a / g->step));
		mlx_pixel_put(prog->mlx, prog->win, c.a, c.b, 0xff0000);
	}
}
*/

void	mandelbrot_set(t_prog *prog, t_complex c)
{
	int			i;
	t_complex	z;
	t_graph		*g;
	int			map[16];

	i = 0;
	z.a = 0;
	z.b = 0;
	get_color(map);
	while (++i < STABLE)
	{
		z = complex_add(complex_mul(z, z), c);
		if (complex_module(z) > 2)
			break ;
	}
	g = &(prog->g);
	c.a = round((c.a / g->step - g->x_bound.a / g->step));
	c.b = round((c.b / g->step - g->y_bound.a / g->step));
	if (i != STABLE)
		mlx_pixel_put(prog->mlx, prog->win, c.a, c.b, map[i % 16]);
}
