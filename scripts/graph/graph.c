/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:53:11 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/08 14:07:43 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_graph(t_graph *g)
{
	g->zoom = 1;
	g->trans.a = 0;
	g->trans.b = 0;
}

void	change_graph(t_graph *g)
{
	g->x_bound.a = -2 / g->zoom + g->trans.a;
	g->x_bound.b = 2 / g->zoom + g->trans.a;
	g->y_bound.a = -2 / g->zoom + g->trans.b;
	g->y_bound.b = 2 / g->zoom + g->trans.b;
	g->step = (g->x_bound.b - g->x_bound.a) / (WIDTH);
	printf("%lf -> %d\n", g->step, (WIDTH * WIDTH * STABLE) / 1000000);
}
