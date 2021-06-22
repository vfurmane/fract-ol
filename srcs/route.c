/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:09:13 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/22 14:58:35 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	route_rendering_set(t_config *config)
{
	if (ft_strcmp(config->set, "julia") == 0)
		render_julia_set(config);
	else if (ft_strcmp(config->set, "mandelbrot") == 0)
		render_mandelbrot_set(config);
}
