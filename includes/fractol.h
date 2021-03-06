/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 11:45:16 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/23 14:28:37 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <complex.h>
# include <float.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"
# include "utils.h"

typedef struct s_mlx_img
{
	void		*ptr;
	void		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_mlx_img;

typedef struct s_mlx_key
{
	int			Up;
	int			Down;
}				t_mlx_key;

typedef struct s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct s_config
{
	void			*mlx;
	void			*win;
	t_mlx_img		img;
	char			*set;
	uint16_t		width;
	uint16_t		height;
	uint8_t			max_iterations;
	uint32_t		bounded_radius;
	complex double	c;
	uint32_t		pixel_size;
	double			scale;
	uint16_t		no_scroll;
	t_coord			center;
}					t_config;

typedef struct s_pixel
{
	uint16_t	x;
	uint16_t	y;
	uint32_t	color;
	uint16_t	size;
}				t_pixel;

uint32_t	julia_algorithm(t_config *config, double x, double y);
uint32_t	mandelbrot_algorithm(t_config *config, double x, double y);

int			check_args(int argc, char **argv);

int			init_mlx(t_config *config);
void		init_parameters(t_config *config, char *set);

void		my_mlx_events(t_config *config);

void		my_mlx_put_pixel(t_mlx_img *img, t_pixel *pixel);

int			print_usage(void);

void		route_rendering_set(t_config *config);

#endif
