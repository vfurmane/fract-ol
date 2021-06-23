/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:51:40 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/23 17:36:27 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_mlx(t_config *config)
{
	config->mlx = mlx_init();
	if (config->mlx == NULL)
		return (-1);
	config->img.ptr = mlx_new_image(config->mlx, config->width, config->height);
	if (config->img.ptr == NULL)
	{
		mlx_destroy_display(config->mlx);
		free(config->mlx);
		return (-1);
	}
	config->img.addr = mlx_get_data_addr(config->img.ptr,
			&config->img.bits_per_pixel, &config->img.size_line,
			&config->img.endian);
	return (1);
}

void	init_parameters(t_config *config, char *set)
{
	config->set = set;
	config->width = 400;
	config->height = 400;
	config->max_iterations = 200;
	config->bounded_radius = 300;
	config->c = -0.7269 + 0.1889 * I;
	config->pixel_size = 1;
	config->scale = 160;
	config->center.x = 0;
	config->center.y = 0;
}
