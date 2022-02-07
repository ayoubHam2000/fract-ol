/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_mouse_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:48:34 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/07 20:50:01 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_toward_mouse(int x, int y, t_prog *prog)
{
	const double	f = 1;
	t_complex		mpos;
	t_complex		cpos;
	t_complex		diff;

	mpos.a = prog->g.step * x + prog->g.x_bound.a;
	mpos.b = prog->g.step * y + prog->g.y_bound.a;
	cpos.a = (prog->g.x_bound.b + prog->g.x_bound.a) / 2;
	cpos.b = (prog->g.y_bound.b + prog->g.y_bound.a) / 2;
	diff.a = (cpos.a - mpos.a) * f;
	diff.b = (cpos.b - mpos.b) * f;
	prog->g.trans.a -= diff.a * (CZOOM);
	prog->g.trans.b -= diff.b * (CZOOM);
}

static void	btn_1_click(int x, int y, t_prog *prog)
{
	prog->old_mpos.a = x;
	prog->old_mpos.b = y;
	prog->old_tran = prog->g.trans;
	prog->mouse_flag = 1;
}

int	on_mouse_down(int button, int x, int y, t_prog *prog)
{
	int		f;

	if (prog->working_flag)
		return (0);
	if (button == 1)
		btn_1_click(x, y, prog);
	if (button == 4 || button == 5)
	{
		f = 1;
		if (button == 4 && prog->g.zoom - CZOOM <= 0.5)
			return (0);
		if (button == 5 && prog->g.zoom + CZOOM >= (double)(1L << 41))
			return (0);
		if (button == 4)
			f = -1;
		prog->g.zoom += CZOOM * prog->g.zoom * f;
		if (button == 5)
			zoom_toward_mouse(x, y, prog);
		change_graph(&prog->g);
		graph_loop(prog);
		printf("%f\n", prog->g.zoom);
	}
	return (0);
}