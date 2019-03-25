/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 17:04:03 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/25 16:34:44 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_pixel_to_img(t_mlx *mlx, int x, int y, int color)
{
	int i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * mlx->bits_per_pixel / 8) + (y * mlx->size_line);
		mlx->data_addr[i] = color;
		mlx->data_addr[++i] = color << 8;
		mlx->data_addr[++i] = color << 16;
	}
}

void		draw_mandelbrot(t_mlx *mlx)
{
	int y;
	int x;
	t_point z;
	double x_new;
	int n;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx->c.x = mlx->position.x + ((x - WIDTH * .5) * 4 / WIDTH) * mlx->zoom;
			mlx->c.y = mlx->position.y + ((y - HEIGHT * .5) * 4 / WIDTH) * mlx->zoom;
			z = mlx->c;
			n = 0;
			while (z.x + z.y <= 2 && n < mlx->max_it)
			{
				x_new = z.x * z.x - z.y * z.y + mlx->c.x;
				z.y = 2 * z.x * z.y + mlx->c.y;
				z.x = x_new;
				n++;
			}
			if (n < mlx->max_it)
				put_pixel_to_img(mlx, x, y, 0xFF);
			else
				put_pixel_to_img(mlx, x, y, 0x000000);
			x++;
		}
		y++;
	}
}
