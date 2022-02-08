/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:35:22 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/08 11:17:09 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_fract(t_prog *prog)
{
	//system("leaks fractol");
	exit(0);
	return (0);
}

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

int main ()
{
	t_prog *prog;

	prog = init_mlx();
	if (!prog)
		return (1);
	graph_loop(prog);
	mlx_hook(prog->win, ON_MOUSEUP, 0, on_mouse_up, prog);
	mlx_hook(prog->win, ON_MOUSEDOWN, 0, on_mouse_down, prog);
	mlx_hook(prog->win, ON_MOUSEMOVE, 0, on_mouse_move, prog);
	mlx_hook(prog->win, ON_KEYUP, 0, on_key_up, prog);
	mlx_hook(prog->win, ON_DESTROY, 0, exit_fract, prog);
	mlx_loop(prog->mlx);
	return (0);	
}
