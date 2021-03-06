/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:34:03 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/23 12:24:22 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

const uint32_t	g_colors[11] = {0x000000, 0xFFE921, 0xF4FF1F, 0xE9FF1F,
								0xDAFF1F, 0xA6FF1F, 0x71FF1F, 0x1FFF5E,
								0x1FFFD2, 0x47D4FF, 0x47C5FF};

static uint8_t	check_julia_radius(double complex nbr,
	double squared_bounded_radius)
{
	double complex	conjugate;
	double			real;
	double			imag;

	conjugate = conj(nbr);
	real = crealf(conjugate);
	imag = cimagf(conjugate);
	return (real * real + imag * imag < squared_bounded_radius);
}

uint32_t	julia_algorithm(t_config *config, double x, double y)
{
	uint8_t			i;
	uint32_t		color;
	double			squared_bounded_radius;
	double complex	nbr;

	i = 0;
	squared_bounded_radius = config->bounded_radius * config->bounded_radius;
	nbr = x - y * I;
	while (check_julia_radius(nbr, squared_bounded_radius) == 1
		&& i < config->max_iterations)
	{
		nbr *= nbr;
		nbr += config->c;
		i++;
	}
	color = g_colors[(int)((double)(config->max_iterations - i)
			/ (double)config->max_iterations
			* (sizeof (g_colors) / sizeof (g_colors[0]) - 1))];
	return (color);
}

static double	squared_modulus(double complex nbr)
{
	double			real;
	double			imag;
	double complex	conjugate;

	conjugate = conj(nbr);
	real = crealf(conjugate);
	imag = cimagf(conjugate);
	return (real * real + imag * imag);
}

uint32_t	mandelbrot_algorithm(t_config *config, double x, double y)
{
	uint32_t		i;
	uint32_t		color;
	double complex	nbr;

	i = 0;
	config->c = x + y * I;
	nbr = 0;
	while (i < config->max_iterations)
	{
		if (fabs(squared_modulus(nbr)) > 4)
			break ;
		nbr *= nbr;
		nbr += config->c;
		i++;
	}
	color = g_colors[(int)((double)(config->max_iterations - i)
			/ (double)config->max_iterations
			* (sizeof (g_colors) / sizeof (g_colors[0]) - 1))];
	return (color);
}
