/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 14:01:12 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/29 14:29:49 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void        *draw_julia(void *data)
{
    int x;
	t_point z;
	t_mlx *mlx;
	double x_new;
	int n;

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
			while (n < mlx->max_it)
			{
				x_new = z.x * z.x - z.y * z.y - 0.8;
				z.y = 2 * z.x * z.y + 0.156;
				z.x = x_new;
				if (fabsl(z.x + z.y) > 6)
					break ;
				n++;
			}
			if (n < mlx->max_it)
				put_pixel_to_img(mlx, x, mlx->cur_y, c_pallette(n, z, mlx));
			x++;
		}
		mlx->cur_y++;
	}
    return (data);
}

void		process_julia(t_mlx *mlx)
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
		pthread_create(&threads[i], NULL, draw_julia, &thread_args[i]);
		i++;
	}
	while (i)
	{
		pthread_join(threads[i], NULL);
		i--;
	}
}