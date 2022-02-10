/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:53:11 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/10 11:45:43 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_graph(t_graph *g)
{
	g->zoom = 1;
	g->trans.a = 0;
	g->trans.b = 0;
}

void	change_graph(t_graph *g, int w_size)
{
	g->x_bound.a = -2 / g->zoom + g->trans.a;
	g->x_bound.b = 2 / g->zoom + g->trans.a;
	g->y_bound.a = -2 / g->zoom + g->trans.b;
	g->y_bound.b = 2 / g->zoom + g->trans.b;
	g->step = (g->x_bound.b - g->x_bound.a) / w_size;
}
