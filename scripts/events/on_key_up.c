/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:35:59 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/08 15:36:17 by aben-ham         ###   ########.fr       */
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
	else if (keycode == KEY_ESC)
		return (exit_fract(prog));
	else
		return (0);
	change_graph(&(prog->g));
	graph_loop(prog);	
	return (0);
}