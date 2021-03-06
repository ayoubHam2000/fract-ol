/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:54:43 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/10 11:39:42 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_prog	*init_prog(void)
{
	t_prog	*prog;

	prog = malloc(sizeof(t_prog));
	if (!prog)
		return (NULL);
	prog->julia_const.a = 0;
	prog->julia_const.b = 0;
	prog->range_shift_color = 1;
	get_colors(prog->color_map);
	prog->f = NULL;
	return (prog);
}

void	*init_mlx(t_prog *prog)
{
	prog->mlx = mlx_init();
	prog->win = mlx_new_window(prog->mlx, prog->w_size, prog->w_size, TITLE);
	prog->img.img = NULL;
	if (!prog->mlx || !prog->win)
		return (NULL);
	return (prog);
}
