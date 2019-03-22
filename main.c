/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:01:26 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/22 17:51:06 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx		*init_window(char *fractol_name)
{
	t_mlx	*mlx;
	
	mlx = MEM(t_mlx);
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, fractol_name);
	mlx->image = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	mlx->data_addr = mlx_get_data_addr(mlx->image, &(mlx->bits_per_pixel), &(mlx->size_line), &(mlx->endian));
	return (mlx);
}

void		check_fractol(char *fractol_name)
{
	/*
	**	Check what Fractol needs to be drawn.
	**	Error if Fractol does not exist and list other fractols as error.
	*/
	if (ft_strcmp(fractol_name, "Mandelbrot") == 0 || ft_strcmp(fractol_name, "mandelbrot") == 0)
		draw_mandelbrot();
	else
	{
		ft_putendl("This is not a correct Fractol, use: Mandelbrot, Juliet, or .....");
		exit(0);
	}
}

void		fractol(char *fractol_name)
{
	t_mlx	*mlx;

	mlx = init_window(fractol_name);
	check_fractol(fractol_name);
	mlx_hook(mlx->win, 2, 1L << 0, deal_key, mlx);
	mlx_loop(mlx->init);
}

int			main(int argc, char **argv)
{
	if (argc <= 1)
		no_params();
	else
		fractol(argv[1]);
	return (0);
}
