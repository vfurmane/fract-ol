/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:51:40 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/22 12:03:15 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_parameters(t_config *config)
{
	config->width = 400;
	config->height = 400;
	config->max_iterations = 200;
	config->bounded_radius = 300;
	config->c = -0.7269 + 0.1889 * I;
	config->pixel_size = 1;
	config->scale = 200;
}
