/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:58:53 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/22 16:10:13 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

const uint32_t	g_mandelbrot_colors[11] = {0x000000, 0xFFE921, 0xF4FF1F, 0xE9FF1F,
								0xDAFF1F, 0xA6FF1F, 0x71FF1F, 0x1FFF5E,
								0x1FFFD2, 0x47D4FF, 0x47C5FF};

static double	squared_modulus(double complex nbr)
{
	double			real;
	double			imag;
	double complex	conjugate;

	conjugate = conj(nbr);
	real = crealf(conjugate);
	imag = cimagf(conjugate);
	return (real * real + imag * imag);
}

static uint32_t	get_color_at_coordinates(t_config *config, double x, double y)
{
	uint32_t		i;
	uint32_t		color;
	double complex	nbr;

	i = 0;
	config->c = x + y * I;
	nbr = 0;
	while (i < config->max_iterations)
	{
		if (fabs(squared_modulus(nbr)) > 4)
			break;
		nbr *= nbr;
		nbr += config->c;
		i++;
	}
	color = g_mandelbrot_colors[(int)((double)(config->max_iterations - i)
			/ (double)config->max_iterations
			* (sizeof (g_mandelbrot_colors) / sizeof (g_mandelbrot_colors[0]) - 1))];
	return (color);
}

void	render_mandelbrot_set(t_config *config)
{
	t_pixel	pixel;

	config->max_iterations = 20;
	pixel.size = config->pixel_size;
	//config->scale = 1;
	pixel.x = 0;
	while (pixel.x < config->width)
	{
		pixel.y = 0;
		while (pixel.y < config->height)
		{
			pixel.color = get_color_at_coordinates(config,
					(pixel.x - config->width / 2) / config->scale,
					(pixel.y - config->height / 2) / config->scale);
			my_mlx_put_pixel(&config->img, &pixel);
			pixel.y += config->pixel_size;
		}
		pixel.x += config->pixel_size;
	}
}
