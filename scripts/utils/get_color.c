/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:27:23 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/08 15:32:41 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_color(int map[])
{
	map[0] = set_rgb(252, 229, 112);
    map[1] = set_rgb(25, 7, 26);
    map[2] = set_rgb(9, 1, 47);
    map[3] = set_rgb(4, 4, 73);
    map[4] = set_rgb(0, 7, 100);
    map[5] = set_rgb(12, 44, 138);
    map[6] = set_rgb(24, 82, 177);
    map[7] = set_rgb(57, 125, 209);
    map[8] = set_rgb(134, 181, 229);
    map[9] = set_rgb(211, 236, 248);
    map[10] = set_rgb(241, 233, 191);
    map[11] = set_rgb(248, 201, 95);
    map[12] = set_rgb(255, 170, 0);
    map[13] = set_rgb(204, 128, 0);
    map[14] = set_rgb(153, 87, 0);
    map[15] = set_rgb(106, 52, 3);
}
