/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 11:45:35 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/22 10:50:36 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

const uint16_t			g_width = 400;
const uint16_t			g_height = 400;
const uint8_t			g_max_iterations = 200;
const uint32_t			g_bounded_radius = 300;
// const complex double	g_c = -0.4 + -0.59 * I;
// const complex double	g_c = 0.37 + 0.1 * I;
const complex double	g_c = -0.7269 + 0.1889 * I;
// const complex double	g_c = -1.417022285618 + 0.0099534 * I;
// const complex double	g_c = 0.285 + 0.01 * I;
const uint32_t			g_setps = 100;
// const int				g_colors[11] = {0x000000, 0x582f0e, 0x7f4f24, 0x936639,
// 										0xa68a64, 0xb6ad90, 0xc2c5aa, 0xa4ac86,
// 										0x656d4a, 0x414833, 0x333d29};
const int				g_colors[11] = {0x000000, 0xFFE921, 0xF4FF1F, 0xE9FF1F, 0xDAFF1F, 0xA6FF1F, 0x71FF1F, 0x1FFF5E, 0x1FFFD2, 0x47D4FF, 0x47C5FF};

uint32_t	get_color_at_coordinates(double x, double y)
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
			my_mlx_put_pixel(&config->img, x, y, color, config->pixel_size);
			y += config->pixel_size;
		}
		x += config->pixel_size;
	}
}

int	main(int argc, char **argv)
{
	t_config	config;
	if (check_args(argc, argv) == 0)
		return (print_usage());
	config.mlx = mlx_init();
	config.img.ptr = mlx_new_image(config.mlx, g_width, g_height);
	config.img.addr = mlx_get_data_addr(config.img.ptr,
			&config.img.bits_per_pixel, &config.img.size_line,
			&config.img.endian);
	if (config.img.endian == 1)
		printf("\033[33mWarning: Your system uses big endian, "
			"the colors may be inaccurate...\n");
	config.scale = 200;
	config.pixel_size = 1;
	render_julia_set(&config);
	config.win = mlx_new_window(config.mlx, g_width, g_height, "fract-ol");
	mlx_put_image_to_window(config.mlx, config.win, config.img.ptr, 0, 0);
	my_mlx_events(&config);
	mlx_loop(config.mlx);
	mlx_destroy_image(config.mlx, config.img.ptr);
	mlx_destroy_window(config.mlx, config.win);
	mlx_destroy_display(config.mlx);
	free(config.mlx);
	return (0);
}
