/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:49:20 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/08 17:20:34 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int on_mouse_move(int x, int y, t_prog *prog)
{
	static t_complex	diff;
	static t_complex	old_tr;

	if (prog->mouse_flag)
	{
		diff.a = (prog->old_mpos.a - x) * prog->g.step;
		diff.b = (prog->old_mpos.b - y) * prog->g.step;
		prog->g.trans.a = prog->old_tran.a + diff.a;
		prog->g.trans.b = prog->old_tran.b + diff.b;
		change_graph(&(prog->g));
		graph_loop(prog);
	}
	else if (prog->julia_flag && x <= WIDTH && x >= 0)
	{
		prog->julia_const.a = (x + prog->g.x_bound.a / prog->g.step ) * prog->g.step;
		prog->julia_const.b = (y + prog->g.y_bound.a / prog->g.step ) * prog->g.step;
		change_graph(&(prog->g));
		graph_loop(prog);
	}
	
	return (0);
}
