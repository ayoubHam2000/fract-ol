/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:01:53 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/07 20:40:32 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "complex.h"

# define WIDTH 200
# define TITLE "fractol"
# define TRAN 0.1
# define CZOOM 0.1
#define STABLE 255

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_graph
{
	t_complex	x_bound;
	t_complex	y_bound;
	t_complex	trans;
	double		zoom;
	double		step;
}	t_graph;

typedef struct s_prog
{
	void		*mlx;
	void		*win;
	int			stable;
	int			mouse_flag;
	int			working_flag;
	t_complex	old_mpos;
	t_complex	old_tran;
	t_graph		g;
}	t_prog;

t_prog	*init_mlx(void);

int	on_mouse_down(int button, int x, int y, t_prog *prog);
int on_mouse_move(int x, int y, t_prog *prog);
int	on_mouse_up(int button, int x, int y, t_prog *prog);

void	graph_loop(t_prog *prog);
void	init_graph(t_graph *g);
void	change_graph(t_graph *g);

void	mandelbrot_set(t_prog *prog, t_complex c);

#endif
