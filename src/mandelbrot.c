/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 17:04:03 by nvreeke        #+#    #+#                */
/*   Updated: 2019/04/11 11:13:20 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Calculates the fractal.
*/

void		calc_mandelbrot(t_mlx *mlx, t_point z, int x, int n)
{
	double	x_new;

	while (x < WIDTH)
	{
		mlx->c.x = mlx->position.x + ((x - WIDTH * .5) * 4 / WIDTH) * mlx->zoom;
		mlx->c.y = mlx->position.y + ((mlx->cur_y - HEIGHT * .5) \
		* 4 / WIDTH) * mlx->zoom;
		z = mlx->c;
		n = 0;
		while (n < mlx->max_it)
		{
			x_new = z.x * z.x - z.y * z.y + mlx->c.x;
			z.y = 2 * z.x * z.y + mlx->c.y;
			z.x = x_new;
			if (fabsl(z.x + z.y) > 6)
				break ;
			n++;
		}
		if (n < mlx->max_it)
			put_pixel_to_img(mlx, x, mlx->cur_y, c_pallette(n, z, mlx));
		x++;
	}
}

/*
**	Draws the fractal on the screen.
*/

void		*draw_mandelbrot(void *data)
{
	int		x;
	t_point z;
	t_mlx	*mlx;
	int		n;

	n = 0;
	z.y = 0;
	z.x = 0;
	mlx = (t_mlx*)data;
	while (mlx->cur_y < mlx->max_y)
	{
		x = 0;
		calc_mandelbrot(mlx, z, x, n);
		mlx->cur_y++;
	}
	return (data);
}

/*
**	Creates multiple threads to make the fractal drawing functions faster.
*/

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
	while (i)
	{
		pthread_join(threads[i], NULL);
		i--;
	}
}
