/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:26:52 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/22 12:04:04 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

const uint32_t	g_colors[11] = {0x000000, 0xFFE921, 0xF4FF1F, 0xE9FF1F,
								0xDAFF1F, 0xA6FF1F, 0x71FF1F, 0x1FFF5E,
								0x1FFFD2, 0x47D4FF, 0x47C5FF};

uint32_t	get_color_at_coordinates(t_config *config, double x, double y)
{
	uint8_t			i;
	uint32_t		color;
	double complex	nbr;
	double complex	conjugate;

	i = 0;
	nbr = x - y * I;
	conjugate = conj(nbr);
	while (crealf(conjugate) * crealf(conjugate)
		+ cimagf(conjugate) * cimagf(conjugate)
		< config->bounded_radius * config->bounded_radius
		&& i < config->max_iterations)
	{
		nbr *= nbr;
		nbr += config->c;
		conjugate = conj(nbr);
		i++;
	}
	color = g_colors[(int)((double)(config->max_iterations - i)
			/ (double)config->max_iterations
			* (sizeof (g_colors) / sizeof (g_colors[0]) - 1))];
	return (color);
}

void	render_julia_set(t_config *config)
{
	t_pixel	pixel;

	pixel.size = config->pixel_size;
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
