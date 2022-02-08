/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:35:22 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/08 18:20:24 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_fract(t_prog *prog)
{
	exit(0);
}

void	help()
{
	printf("Help\n");
}

void	controller(int ac, char **av, t_prog *prog)
{
	if (ac == 1)
		help();
	else
	{
		if (ft_atof(av[1]) == 1.0)
			prog->f = mandelbrot_set;
		else if (ft_atof(av[1]) == 2.0)
		{
			if (ac < 4)
				return (help());
			prog->julia_const.a = ft_atof(av[2]);
			prog->julia_const.a = ft_atof(av[3]);
			prog->f = julia_set;
		}
	}
	graph_loop(prog);
}

int main (int ac, char **av)
{
	t_prog *prog;

	prog = init_mlx();
	if (!prog)
		return (1);
	controller(ac, av, prog);
	mlx_hook(prog->win, ON_MOUSEUP, 0, on_mouse_up, prog);
	mlx_hook(prog->win, ON_MOUSEDOWN, 0, on_mouse_down, prog);
	mlx_hook(prog->win, ON_MOUSEMOVE, 0, on_mouse_move, prog);
	mlx_hook(prog->win, ON_KEYUP, 0, on_key_up, prog);
	mlx_hook(prog->win, ON_DESTROY, 0, exit_fract, prog);
	mlx_loop(prog->mlx);
	return (0);	
}
