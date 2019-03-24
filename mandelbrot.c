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

void		set_image_dims(t_dim *dim)
{
	dim->min_real = -2.0;
	dim->max_real = 1.0;
	dim->min_imagine = -1.2;
	dim->max_imagine = dim->min_imagine + (dim->max_real - dim->min_real) * HEIGHT / WIDTH;
	dim->re_factor = (dim->max_real - dim->min_real) / (WIDTH - 1);
 	dim->im_factor = (dim->max_imagine - dim->min_imagine) / (HEIGHT - 1);
}

void	draw_mandelbrot(t_dim *dim, t_mlx *mlx)
{
	int y;
	int x;
	unsigned int n;
	set_image_dims(dim);
	mlx_destroy_image(mlx->init, mlx->image);

	y = 0;
	x = 0;
	n = 0;
	while (y < HEIGHT)
	{
		double c_im = dim->max_imagine - y * dim->im_factor;
		while (x < WIDTH)
		{
			double c_real = dim->min_real + x * dim->re_factor;

			double z_real = c_real;
			double z_imagine = c_im;
			double isInside = 1;
			while (n < MAX_IT)
			{
				double Z_re2 = z_real * z_real, z_im2 = z_imagine * z_imagine;

				if (z_real * z_real + z_imagine * z_imagine > 4)
				{
					isInside = 0;
					break ;
				}
				z_imagine = 2 * z_real * z_imagine + c_im;
				z_real = Z_re2 - z_im2 + c_real;
				n++;
			}
			if (isInside)
				mlx_pixel_put(mlx->init, mlx->win, x, y, 0xFF << 8);
			x++;
		}
		y++;
	}
}
