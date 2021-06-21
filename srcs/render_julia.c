/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:26:52 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/21 13:21:05 by vfurmane         ###   ########.fr       */
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
	int16_t		x;
	int16_t		y;
	uint32_t	color;

	x = 0;
	while (x < g_width)
	{
		y = 0;
		while (y < g_height)
		{
			color = get_color_at_coordinates((x - g_width / 2) / config->scale,
					(y - g_height / 2) / config->scale);
			my_mlx_put_pixel(&config->img, x, y, color);
			y++;
		}
		x++;
	}
}
