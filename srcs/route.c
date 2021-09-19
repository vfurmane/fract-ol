/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:09:13 by vfurmane          #+#    #+#             */
/*   Updated: 2021/09/19 14:54:10 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*render_set(void *arg)
{
	t_pixel		pixel;
	t_config	config;

	pthread_mutex_lock(&((t_config *)arg)->lock);
	config = *(t_config *)arg;
	pthread_mutex_unlock(&((t_config *)arg)->lock);
	pixel.size = config.pixel_size;
	pixel.x = config.compute_start;
	while (pixel.x < config.compute_start + config.compute_number)
	{
		pixel.y = 0;
		while (pixel.y < config.height)
		{
			pixel.color = config.algorithm(&config,
					config.center.x + (pixel.x - config.width / 2)
					/ config.scale,
					config.center.y + (pixel.y - config.height / 2)
					/ config.scale);
			pthread_mutex_lock(&((t_config *)arg)->lock);
			my_mlx_put_pixel(&config.img, &pixel);
			pthread_mutex_unlock(&((t_config *)arg)->lock);
			pixel.y += config.pixel_size;
		}
		pixel.x += config.pixel_size;
	}
	return (NULL);
}

#undef THREADS_NB
#define THREADS_NB 4

void	route_rendering_set(t_config *config)
{
	int			i;
	pthread_t	threads[THREADS_NB];
	t_config	configs[THREADS_NB];

	if (ft_strcmp(config->set, "julia") == 0)
		config->algorithm = julia_algorithm;
	else if (ft_strcmp(config->set, "mandelbrot") == 0)
	{
		config->max_iterations = 240;
		config->algorithm = mandelbrot_algorithm;
	}
	config->compute_number = config->width / THREADS_NB;
	if (pthread_mutex_init(&config->lock, NULL) != 0)
		return ;
	i = 0;
	while (i < THREADS_NB)
	{
		ft_memcpy(&configs[i], config, sizeof (*config));
		configs[i].compute_start = i * config->compute_number;
		pthread_create(&threads[i], NULL, render_set, &configs[i]);
		i++;
	}
	i = 0;
	while (i < THREADS_NB)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	if (pthread_mutex_destroy(&config->lock) != 0)
		return ;
}
