/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:09:13 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/22 21:41:03 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	render_set(t_config *config, uint32_t (*get_color_at_coordinates)(t_config *, double, double))
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
					config->center.x + (pixel.x - config->width / 2) / config->scale,
					config->center.y + (pixel.y - config->height / 2) / config->scale);
			my_mlx_put_pixel(&config->img, &pixel);
			pixel.y += config->pixel_size;
		}
		pixel.x += config->pixel_size;
	}
}

void	route_rendering_set(t_config *config)
{
	if (ft_strcmp(config->set, "julia") == 0)
		render_set(config, julia_algorithm);
	else if (ft_strcmp(config->set, "mandelbrot") == 0)
	{
		config->max_iterations = 25;
		render_set(config, mandelbrot_algorithm);
	}
}
