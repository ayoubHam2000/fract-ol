/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:35:22 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/03 21:30:38 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	line(int startX, int startY, int endX, int endY, void *mlx, void *win)
{
	double slope = (double)(endY - startY) / (endX - startX);
	double resolution = 1;
	double x = startX;
	while (x <= endX)
	{
		double y = slope * (x - startX) + startY;
		mlx_pixel_put(mlx,win,x,y,0Xffffff);
		x += resolution;
	}
}

int main ()
{
	void *mlx;
	void *win;
	mlx = mlx_init();
	win = mlx_new_window(mlx,1000,1000,"fract");
	line(500, 600, 900, 600, mlx, win);
	line(10, 10, 500, 600, mlx, win);
	line(10, 10, 900, 600, mlx, win);
	mlx_loop(mlx);
	return (0);	
}
