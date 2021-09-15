/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:09:13 by vfurmane          #+#    #+#             */
/*   Updated: 2021/09/15 14:19:38 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	render_set(t_config *config)
{
	t_pixel	pixel;

	pixel.size = config->pixel_size;
	pixel.x = 0;
	while (pixel.x < config->width)
	{
		pixel.y = 0;
		while (pixel.y < config->height)
		{
			pixel.color = config->algorithm(config,
					config->center.x + (pixel.x - config->width / 2)
					/ config->scale,
					config->center.y + (pixel.y - config->height / 2)
					/ config->scale);
			my_mlx_put_pixel(&config->img, &pixel);
			pixel.y += config->pixel_size;
		}
		pixel.x += config->pixel_size;
	}
}

void	route_rendering_set(t_config *config)
{
	if (ft_strcmp(config->set, "julia") == 0)
		config->algorithm = julia_algorithm;
	else if (ft_strcmp(config->set, "mandelbrot") == 0)
	{
		config->max_iterations = 240;
		config->algorithm = mandelbrot_algorithm;
	}
	render_set(config);
}
