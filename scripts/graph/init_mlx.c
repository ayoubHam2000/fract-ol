/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:54:43 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/08 18:24:03 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_prog	*init_mlx(void)
{
	t_prog	*prog;

	prog = malloc(sizeof(t_prog));
	if (!prog)
		return (NULL);
	prog->mlx = mlx_init();
	prog->win = mlx_new_window(prog->mlx, WIDTH, WIDTH, TITLE);
	if (!prog->mlx || !prog->win)
		return (NULL);
	init_graph(&(prog->g));
	change_graph(&(prog->g));
	prog->julia_const.a = 0;
	prog->julia_const.b = 0;
	prog->f = NULL;
	return (prog);
}
