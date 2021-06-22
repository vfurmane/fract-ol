/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:26:52 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/22 11:03:21 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t	get_color_at_coordinates(double x, double y)
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
		< g_bounded_radius * g_bounded_radius && i < g_max_iterations)
	{
		nbr *= nbr;
		nbr += g_c;
		conjugate = conj(nbr);
		i++;
	}
	color = g_colors[(int)((double)(g_max_iterations - i)
			/ (double)g_max_iterations
			* (sizeof (g_colors) / sizeof (g_colors[0]) - 1))];
	return (color);
}

void	render_julia_set(t_config *config)
{
	t_pixel	pixel;

	pixel.size = config.pixel_size;
	pixel.x = 0;
	while (pixel.x < g_width)
	{
		pixel.y = 0;
		while (pixel.y < g_height)
		{
			pixel.color = get_color_at_coordinates((pixel.x - g_width / 2)
					/ config->scale, (pixel.y - g_height / 2) / config->scale);
			my_mlx_put_pixel(&config->img, &pixel);
			pixel.y++;
		}
		pixel.x++;
	}
}
