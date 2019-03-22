/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 17:04:03 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/22 17:48:49 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_image_dims(void)
{
	t_dim	*dim;
	
	dim = MEM(t_dim);
	dim->min_real = -2.0;
	dim->max_real = 1.0;
	dim->min_imagine = -1.2;
	dim->max_imagine = dim->min_imagine + (dim->max_real - dim->min_real) * HEIGHT / WIDTH;
}

void	draw_mandelbrot(void)
{
	set_image_dims();
}
