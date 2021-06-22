/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:09:13 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/22 12:25:50 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	route_rendering_set(t_config *config)
{
	if (ft_strcmp(config->set, "julia") == 0)
		render_julia_set(config);
}
