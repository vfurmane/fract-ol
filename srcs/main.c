/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 11:45:35 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/20 22:38:33 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

const uint16_t			g_width = 400;
const uint16_t			g_height = 400;
const uint8_t			g_max_iterations = 100;
const uint16_t			g_bounded_radius = 25;
const double			g_scale = 150;
const complex double	g_c = 0.8 * I;

uint32_t	get_color_at_coordinates(double x, double y)
{
	uint8_t			i;
	double complex	nbr;
	double complex	conjugate;

	i = 0;
	nbr = x - y * I;
	conjugate = conj(nbr);
	while (crealf(conjugate) * crealf(conjugate)
		+ cimagf(conjugate) * cimagf(conjugate)
		< g_bounded_radius * g_bounded_radius && i < g_max_iterations)
	{
		conjugate = conj(nbr);
		nbr *= nbr;
		nbr -= g_c;
		conjugate = conj(nbr);
		i++;
	}
	return (0xFFFFFF / g_max_iterations * i);
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
