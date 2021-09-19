/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hintauh <hintauh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 18:13:57 by vfurmane          #+#    #+#             */
/*   Updated: 2021/09/19 16:54:26 by hintauh          ###   ########.fr       */
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
	else if (config->no_scroll < 100)
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

static int	my_mlx_mouse(int code, int x, int y, t_config *config)
{
	if (code == Button4 || (code == Button5 && config->scale >= 1.25))
	{
		config->center.x += (x - config->width / 2) / config->scale;
		config->center.y += (y - config->height / 2) / config->scale;
		if (code == Button4)
			config->scale *= 1.25;
		else
		{
			if (config->scale == INFINITY)
				config->scale = DBL_MAX;
			else
				config->scale /= 1.25;
		}
		config->center.x -= (x - config->width / 2) / config->scale;
		config->center.y -= (y - config->height / 2) / config->scale;
		config->pixel_size = 10;
		config->no_scroll = 0;
	}
	else
		return (1);
	route_rendering_set(config);
	mlx_put_image_to_window(config->mlx, config->win, config->img.ptr, 0, 0);
	return (0);
}

void	my_mlx_events(t_config *config)
{
	config->no_scroll = 101;
	mlx_loop_hook(config->mlx, my_mlx_loop_hook, config);
	mlx_hook(config->win, ClientMessage, StructureNotifyMask,
		my_mlx_close_window, config->mlx);
	mlx_hook(config->win, KeyPress, KeyPressMask, my_mlx_handle_key, config);
	mlx_hook(config->win, ButtonPress, ButtonPressMask, my_mlx_mouse, config);
}
