/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 17:04:03 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/26 14:54:33 by nvreeke       ########   odam.nl         */
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
		mlx->data_addr[++i] = color >> 8;
		mlx->data_addr[++i] = color >> 16;
	}
}

double		dot_product(t_point p)
{
	return (p.x * p.x + p.y * p.y);
}

void		*draw_mandelbrot(void *data)
{
	int x;
	t_point z;
	t_mlx *mlx;
	double x_new;
	double n;

	mlx = (t_mlx*)data;
	while (mlx->cur_y < mlx->max_y)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx->c.x = mlx->position.x + ((x - WIDTH * .5) * 4 / WIDTH) * mlx->zoom;
			mlx->c.y = mlx->position.y + ((mlx->cur_y - HEIGHT * .5) * 4 / WIDTH) * mlx->zoom;
			z = mlx->c;
			n = 0;
			while (fabsl(z.x + z.y) <= 2 && n < mlx->max_it)
			{
				x_new = z.x * z.x - z.y * z.y + mlx->c.x;
				z.y = 2 * z.x * z.y + mlx->c.y;
				z.x = x_new;
				n++;
			}
			if (n < mlx->max_it)
			{
				int bright = n - log2(log2(dot_product(z))) + 60.0;//(n / mlx->max_it) * 255;
				int color = 0;
				color |= bright;
				color |= bright << 8;
				color |= bright << 16;
				put_pixel_to_img(mlx, x, mlx->cur_y, color);
			}
			else
				put_pixel_to_img(mlx, x, mlx->cur_y, 0x000000);
			x++;
		}
		mlx->cur_y++;
	}
	return (data);
}

void		process_mandelbrot(t_mlx *mlx)
{
	int			i;
	pthread_t	threads[NUM_THREADS];
	t_mlx		thread_args[NUM_THREADS];

	i = 0;
	while (i < NUM_THREADS)
	{
		ft_memcpy(&thread_args[i], mlx, sizeof(t_mlx));
		mlx->max_y = (i + 1) * (HEIGHT / NUM_THREADS);
		mlx->cur_y = i * (HEIGHT / NUM_THREADS);
		pthread_create(&threads[i], NULL, draw_mandelbrot, &thread_args[i]);
		i++;
	}
	while (i--)
	{
		pthread_join(threads[i], NULL);
	}
}
