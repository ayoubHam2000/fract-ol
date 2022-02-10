/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:01:53 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/10 11:46:41 by aben-ham         ###   ########.fr       */
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

//# define WIDTH 300
# define TITLE "fractol"
# define TRAN 0.5
# define CZOOM 0.2
//# define STABLE 100

# define KEY_L 123
# define KEY_R 124
# define KEY_U 126
# define KEY_D 125
# define KEY_ESC 53

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_complex
{
	long double	a;
	long double	b;
}	t_complex;

typedef struct s_graph
{
	t_complex		x_bound;
	t_complex		y_bound;
	t_complex		trans;
	long double		zoom;
	long double		step;
}	t_graph;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_prog	t_prog;
struct s_prog
{
	void		*mlx;
	void		*win;
	int			w_size;
	int			depth;
	t_data		img;
	t_complex	julia_const;
	t_graph		g;
	int			color_map[16];
	double		range_shift_color;
	void		(*f)(t_prog *prog, t_complex c);
} ;

t_prog	*init_prog(void);
void	*init_mlx(t_prog *prog);

int		on_mouse_down(int button, int x, int y, t_prog *prog);
int		on_key_up(int keycode, t_prog *prog);

void	init_graph(t_graph *g);
void	change_graph(t_graph *g, int w_size);
void	graph_loop(t_prog *prog);

void	mandelbrot_set(t_prog *prog, t_complex c);
void	julia_set(t_prog *prog, t_complex c);
void	bonus_fract(t_prog *prog, t_complex p);

void	get_colors(int *map);
double	ft_atof(const char *str);
void	ft_put_str(char *str);
void	mlx_img_pixel_put(t_prog *prog, int x, int y, int color);
int		ft_atoi(const char *str);
void	*replace_image(t_prog *prog);
int		exit_fractol(t_prog *prog);
void	check_args(int ac, char **av);

#endif
