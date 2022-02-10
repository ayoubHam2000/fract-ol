/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:35:22 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/10 11:56:48 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol(int ac, char **av, t_prog *prog)
{
	if (ft_atoi(av[3]) == 1)
		prog->f = mandelbrot_set;
	else if (ft_atoi(av[3]) == 2)
		prog->f = julia_set;
	else if (ft_atoi(av[3]) == 3)
		prog->f = bonus_fract;
	if (ac >= 5)
		prog->julia_const.a = ft_atof(av[4]);
	if (ac >= 6)
		prog->julia_const.b = ft_atof(av[5]);
	init_graph(&(prog->g));
	change_graph(&(prog->g), prog->w_size);
	graph_loop(prog);
}

int	main(int ac, char **av)
{
	t_prog	*prog;

	check_args(ac, av);
	prog = init_prog();
	if (!prog)
		return (1);
	prog->w_size = ft_atoi(av[1]);
	prog->depth = ft_atoi(av[2]);
	if (!init_mlx(prog))
		return (1);
	fractol(ac, av, prog);
	mlx_hook(prog->win, ON_MOUSEDOWN, 0, on_mouse_down, prog);
	mlx_hook(prog->win, ON_KEYUP, 0, on_key_up, prog);
	mlx_hook(prog->win, ON_DESTROY, 0, exit_fractol, prog);
	mlx_loop(prog->mlx);
	return (0);
}
