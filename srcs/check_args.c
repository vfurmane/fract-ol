/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:00:34 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/20 17:09:42 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (ft_strcmp("julia", argv[1]) != 0
		&& ft_strcmp("mandelbrot", argv[1]) != 0)
		return (0);
	return (1);
}
