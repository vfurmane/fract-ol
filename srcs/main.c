/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 11:45:35 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/23 14:28:11 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_config	config;

	if (check_args(argc, argv) == 0)
		return (print_usage());
	init_parameters(&config, argv[1]);
	if (init_mlx(&config) < 1)
		return (1);
	if (config.img.endian == 1)
		printf("\033[33mWarning: Your system uses big endian, "
			"the colors may be inaccurate...\n");
	route_rendering_set(&config);
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
