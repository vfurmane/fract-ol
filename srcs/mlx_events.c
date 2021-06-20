/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 18:13:57 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/20 18:14:06 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

static int	my_mlx_handle_key(int code, void *mlx)
{
	if (code == XK_Escape)
		my_mlx_close_window(mlx);
	return (0);
}

void	my_mlx_events(void *mlx, void *win)
{
	mlx_loop_hook(mlx, my_mlx_loop_hook, NULL);
	mlx_hook(win, ClientMessage, StructureNotifyMask,
		my_mlx_close_window, mlx);
	mlx_hook(win, KeyPress, KeyPressMask, my_mlx_handle_key, mlx);
}
