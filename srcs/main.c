/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 11:45:35 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/22 12:03:23 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_config	config;

	if (check_args(argc, argv) == 0)
		return (print_usage());
	init_parameters(&config);
	config.mlx = mlx_init();
	config.img.ptr = mlx_new_image(config.mlx, config.width, config.height);
	config.img.addr = mlx_get_data_addr(config.img.ptr,
			&config.img.bits_per_pixel, &config.img.size_line,
			&config.img.endian);
	if (config.img.endian == 1)
		printf("\033[33mWarning: Your system uses big endian, "
			"the colors may be inaccurate...\n");
	render_julia_set(&config);
	config.win = mlx_new_window(config.mlx, config.width, config.height,
			"fract-ol");
	mlx_put_image_to_window(config.mlx, config.win, config.img.ptr, 0, 0);
	my_mlx_events(&config);
	mlx_loop(config.mlx);
	mlx_destroy_image(config.mlx, config.img.ptr);
	mlx_destroy_window(config.mlx, config.win);
	mlx_destroy_display(config.mlx);
	free(config.mlx);
	return (0);
}
