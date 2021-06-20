/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 11:45:35 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/20 23:11:46 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

const uint16_t			g_width = 800;
const uint16_t			g_height = 800;
const uint8_t			g_max_iterations = 20;
const uint32_t			g_bounded_radius = 1000;
const double			g_scale = 300;
const complex double	g_c = 0.8 * I;
const int				g_colors[11] = {0x000000, 0x582f0e, 0x7f4f24, 0x936639,
										0xa68a64, 0xb6ad90, 0xc2c5aa, 0xa4ac86,
										0x656d4a, 0x414833, 0x333d29};

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
	if (i == g_max_iterations)
		color = 0;
	else
		color = 0x582f0e;
	color = g_colors[(int)((double)(g_max_iterations - i)
			/ (double)g_max_iterations
			* (sizeof (g_colors) / sizeof (g_colors[0]) - 1))];
	return (color);
}

void	render_julia_set(t_mlx_img *img)
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
			color = get_color_at_coordinates((x - g_width / 2) / g_scale,
					(y - g_height / 2) / g_scale);
			my_mlx_put_pixel(img, x, y, color);
			y++;
		}
		x++;
	}
}

int	main(int argc, char **argv)
{
	void		*mlx;
	void		*win;
	t_mlx_img	img;

	if (check_args(argc, argv) == 0)
		return (print_usage());
	mlx = mlx_init();
	img.ptr = mlx_new_image(mlx, g_width, g_height);
	img.addr = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.size_line,
			&img.endian);
	if (img.endian == 1)
		printf("\033[33mWarning: Your system uses big endian, "
			"the colors may be inaccurate...\n");
	render_julia_set(&img);
	win = mlx_new_window(mlx, g_width, g_height, "fract-ol");
	mlx_put_image_to_window(mlx, win, img.ptr, 0, 0);
	my_mlx_events(mlx, win);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, img.ptr);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}
