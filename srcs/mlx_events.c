/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 18:13:57 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/22 12:28:52 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	my_mlx_loop_hook(t_config *config)
{
	if (config->no_scroll == 100)
	{
		config->pixel_size = 1;
		route_rendering_set(config);
		mlx_put_image_to_window(config->mlx, config->win, config->img.ptr,
			0, 0);
		config->no_scroll++;
	}
	else
		config->no_scroll++;
	return (0);
}

static int	my_mlx_close_window(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

static int	my_mlx_handle_key(int code, t_config *config)
{
	if (code == XK_Escape)
		my_mlx_close_window(config->mlx);
	return (0);
}

static int	my_mlx_scroll(int code, int	x, int y, t_config *config)
{
	(void)x;
	(void)y;
	if (code == Button4)
	{
		config->pixel_size = 10;
		config->no_scroll = 0;
		config->scale *= 1.25;
		route_rendering_set(config);
		mlx_put_image_to_window(config->mlx, config->win, config->img.ptr,
			0, 0);
	}
	else if (code == Button5 && config->scale >= 1.25)
	{
		config->pixel_size = 10;
		config->no_scroll = 0;
		if (config->scale == INFINITY)
			config->scale = DBL_MAX;
		else
			config->scale /= 1.25;
		route_rendering_set(config);
		mlx_put_image_to_window(config->mlx, config->win, config->img.ptr,
			0, 0);
	}
	return (0);
}

void	my_mlx_events(t_config *config)
{
	config->no_scroll = 0;
	mlx_loop_hook(config->mlx, my_mlx_loop_hook, config);
	mlx_hook(config->win, ClientMessage, StructureNotifyMask,
		my_mlx_close_window, config->mlx);
	mlx_hook(config->win, KeyPress, KeyPressMask, my_mlx_handle_key, config);
	mlx_hook(config->win, ButtonPress, ButtonPressMask, my_mlx_scroll, config);
}
