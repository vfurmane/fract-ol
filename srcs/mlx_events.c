/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 18:13:57 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/21 15:41:34 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//	config->scale += 10;
//	render_julia_set(config);
//	mlx_put_image_to_window(config->mlx, config->win, config->img.ptr, 0, 0);

static int	my_mlx_loop_hook(void *param)
{
	(void)param;
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
		config->scale *= 1.25;
		render_julia_set(config);
		mlx_put_image_to_window(config->mlx, config->win, config->img.ptr, 0, 0);
	}
	else if (code == Button5 && config->scale >= 1.25)
	{
		config->scale /= 1.25;
		render_julia_set(config);
		mlx_put_image_to_window(config->mlx, config->win, config->img.ptr, 0, 0);
	}
	return (0);
}

void	my_mlx_events(t_config *config)
{
	mlx_loop_hook(config->mlx, my_mlx_loop_hook, NULL);
	mlx_hook(config->win, ClientMessage, StructureNotifyMask,
		my_mlx_close_window, config->mlx);
	mlx_hook(config->win, KeyPress, KeyPressMask, my_mlx_handle_key, config);
	mlx_mouse_hook(config->win, my_mlx_scroll, config);
	//mlx_hook(config->win, ButtonPress, ButtonPressMask, my_mlx_handle_key, config);
}
