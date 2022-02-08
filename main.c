/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:35:22 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/08 15:36:20 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_fract(t_prog *prog)
{
	//system("leaks fractol");
	exit(0);
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
