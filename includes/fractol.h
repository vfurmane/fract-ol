/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 11:45:16 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/20 21:52:20 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <complex.h>
# include <stdint.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"
# include "utils.h"

typedef struct s_mlx_img
{
	void		*ptr;
	void		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_mlx_img;

int		check_args(int argc, char **argv);

void	my_mlx_events(void *mlx, void *win);

void	my_mlx_put_pixel(t_mlx_img *img, int x, int y, int color);

int		print_usage(void);

#endif
