/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_mouse_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:49:41 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/08 10:32:52 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_mouse_up(int button, int x, int y, t_prog *prog)
{
	if (button == 1)
		prog->mouse_flag = 0;
	return (0);
}
