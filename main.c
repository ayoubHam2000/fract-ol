/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:35:22 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/09 17:34:42 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol(int ac, char **av, t_prog *prog)
{
	if (ft_atoi(av[1]) == 1)
		prog->f = mandelbrot_set;
	else if (ft_atoi(av[1]) == 2)
		prog->f = julia_set;
	else if (ft_atoi(av[1]) == 3)
		prog->f = bonus_fract;
	if (ac >= 3)
		prog->julia_const.a = ft_atof(av[2]);
	if (ac >= 4)
		prog->julia_const.b = ft_atof(av[3]);
	init_graph(&(prog->g));
	change_graph(&(prog->g));
	graph_loop(prog);
}

int	main(int ac, char **av)
{
	t_prog	*prog;

	check_args(ac, av);
	prog = init_prog();
	if (!prog)
		return (1);
	if (!init_mlx(prog))
		return (1);
	fractol(ac, av, prog);
	mlx_hook(prog->win, ON_MOUSEDOWN, 0, on_mouse_down, prog);
	mlx_hook(prog->win, ON_KEYUP, 0, on_key_up, prog);
	mlx_hook(prog->win, ON_DESTROY, 0, exit_fractol, prog);
	mlx_loop(prog->mlx);
	return (0);
}
