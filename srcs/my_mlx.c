/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 21:49:00 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/21 13:53:33 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_put_pixel(t_mlx_img *img, int x, int y, int color, uint32_t pixel_size)
{
	uint32_t		i;
	uint32_t		j;
	char			*dest;

	i = 0;
	while (i < pixel_size)
	{
		j = 0;
		while (j < pixel_size)
		{
			dest = img->addr + ((int)(y + j) * img->size_line
					+ (int)(x + i) * (img->bits_per_pixel / 8));
			*(unsigned int *)dest = color;
			j++;
		}
		i++;
	}
}
