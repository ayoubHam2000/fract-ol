/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:35:22 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/07 19:42:04 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	mlx_loop(prog->mlx);
	return (0);	
}
