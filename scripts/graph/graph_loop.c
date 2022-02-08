/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:41:27 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/08 18:15:38 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	graph_loop(t_prog *prog)
{
	t_complex	x_bound;
	t_complex	y_bound;
	t_complex	c;
	long double		step;

	mlx_clear_window(prog->mlx, prog->win);
	x_bound = prog->g.x_bound;
	y_bound = prog->g.y_bound;
	step = prog->g.step;
	c.a = x_bound.a;
	while (c.a < x_bound.b)
	{
		c.b = y_bound.a;
		while (c.b < y_bound.b)
		{
			prog->f(prog, c);
			c.b = c.b + step;
		}
		c.a = c.a + step;
	}
}
