/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:35:59 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/10 11:47:07 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_key_up(int keycode, t_prog *prog)
{
	if (keycode == KEY_L)
		prog->g.trans.a = prog->g.trans.a - TRAN / prog->g.zoom;
	else if (keycode == KEY_R)
		prog->g.trans.a = prog->g.trans.a + TRAN / prog->g.zoom;
	else if (keycode == KEY_U)
		prog->g.trans.b = prog->g.trans.b - TRAN / prog->g.zoom;
	else if (keycode == KEY_D)
		prog->g.trans.b = prog->g.trans.b + TRAN / prog->g.zoom;
	else if (keycode == 12)
		prog->range_shift_color *= cos(prog->range_shift_color * 0.1);
	else if (keycode == KEY_ESC)
		return (exit_fractol(prog));
	else
		return (0);
	change_graph(&(prog->g), prog->w_size);
	graph_loop(prog);
	return (0);
}
