/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_mouse_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:48:34 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/10 11:47:19 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_toward_mouse(int x, int y, t_prog *prog)
{
	t_complex	mpos;
	t_complex	cpos;
	t_complex	diff;

	mpos.a = prog->g.step * x + prog->g.x_bound.a;
	mpos.b = prog->g.step * y + prog->g.y_bound.a;
	cpos.a = (prog->g.x_bound.b + prog->g.x_bound.a) / 2;
	cpos.b = (prog->g.y_bound.b + prog->g.y_bound.a) / 2;
	diff.a = (cpos.a - mpos.a);
	diff.b = (cpos.b - mpos.b);
	prog->g.trans.a -= diff.a * (CZOOM);
	prog->g.trans.b += diff.b * (CZOOM);
}

int	on_mouse_down(int button, int x, int y, t_prog *prog)
{
	int		f;

	if (button == 4 || button == 5)
	{
		f = 1;
		if (button == 4 && prog->g.zoom - CZOOM <= 0.5)
			return (0);
		if (button == 5 && prog->g.zoom + CZOOM >= (long double)(1L << 42))
			return (0);
		if (button == 4)
			f = -1;
		if (button == 5)
			zoom_toward_mouse(x, y, prog);
		prog->g.zoom += CZOOM * prog->g.zoom * f;
		change_graph(&prog->g, prog->w_size);
		graph_loop(prog);
	}
	return (0);
}
