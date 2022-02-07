/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:49:20 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/07 20:33:48 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int on_mouse_move(int x, int y, t_prog *prog)
{
	static t_complex	diff;
	static t_complex	old_tr;
	double				tran;

	if (prog->working_flag)
		return (0);
	if (prog->mouse_flag)
	{
		diff.a = (prog->old_mpos.a - x) * prog->g.step;
		diff.b = (prog->old_mpos.b - y) * prog->g.step;
		tran = TRAN / prog->g.zoom;
		prog->g.trans.a = prog->old_tran.a + diff.a;
		prog->g.trans.b = prog->old_tran.b + diff.b;
		change_graph(&(prog->g));
		graph_loop(prog);
	}
	return (0);
}
