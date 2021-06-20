/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 21:49:00 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/20 22:39:04 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_put_pixel(t_mlx_img *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + ((int)y * img->size_line
			+ (int)x * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}
