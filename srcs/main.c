/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 11:45:35 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/20 18:13:50 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

const int	g_width = 400;
const int	g_height = 400;

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
	win = mlx_new_window(mlx, g_width, g_height, "fract-ol");
	my_mlx_events(mlx, win);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, img.ptr);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}
