/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:35:22 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/08 21:21:20 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_fract(t_prog *prog)
{
	free(prog);
	exit(0);
}

static void	help(t_prog *prog)
{
	ft_put_str("\n");
	ft_put_str("fractol <fractal_nbr>");
	ft_put_str("[julia_reel_const] [julia_imaginary_const]\n\n");
	ft_put_str("fractal_nbr\n");
	ft_put_str("\t1 : Mandelbrot set\n");
	ft_put_str("\t2 : Julia set\n");
	ft_put_str("\t3 : Nova set\n\n");
	ft_put_str("Default values of julia_reel_const and");
	ft_put_str("julia_imaginary_const is 0\n\n");
	ft_put_str("Info: \n");
	ft_put_str("\t-Arrows keys for moving the view\n");
	ft_put_str("\t-Zoom out and in using the mouse wheel\n");
	ft_put_str("\t-ESC for exit\n\n");
	ft_put_str("Example : ./fractol 2 0 -0.8\n\n");
	exit_fract(prog);
}

void	controller(int ac, char **av, t_prog *prog)
{
	if (ft_atof(av[1]) == 1.0)
		prog->f = mandelbrot_set;
	else if (ft_atof(av[1]) == 2.0)
	{
		if (ac >= 3)
			prog->julia_const.a = ft_atof(av[2]);
		if (ac >= 4)
			prog->julia_const.b = ft_atof(av[3]);
		prog->f = julia_set;
	}
	else if (ft_atof(av[1]) == 3.0)
		prog->f = nova_set;
	if (!prog->f)
		help(prog);
}

int main (int ac, char **av)
{
	t_prog *prog;

	if (ac == 1)
	{
		help(prog);
		exit(0);
	}
	prog = init_prog();
	if (!prog)
		return (1);
	controller(ac, av, prog);
	if (!init_mlx(prog))
		return (1);
	graph_loop(prog);
	mlx_hook(prog->win, ON_MOUSEDOWN, 0, on_mouse_down, prog);
	mlx_hook(prog->win, ON_KEYUP, 0, on_key_up, prog);
	mlx_hook(prog->win, ON_DESTROY, 0, exit_fract, prog);
	mlx_loop(prog->mlx);
	return (0);	
}
