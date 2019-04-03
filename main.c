/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:01:26 by nvreeke        #+#    #+#                */
/*   Updated: 2019/04/03 12:35:35 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Initialize function
*/

t_mlx		*init_window(char *fractol_name)
{
	t_mlx	*mlx;
	
	mlx = MEM(t_mlx);
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, fractol_name);
	mlx->image = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	mlx->data_addr = mlx_get_data_addr(mlx->image, &(mlx->bits_per_pixel), &(mlx->size_line), &(mlx->endian));
	mlx->zoom = 1;
	mlx->max_it = 40;
	mlx->tab = 0;
	mlx->button = 0;
	return (mlx);
}

/*
**	Clears image with bzero, runs draw fractol function and puts new image to window.
*/

int			process_fract(t_mlx *mlx)
{
	ft_bzero(mlx->data_addr, HEIGHT * WIDTH * (mlx->bits_per_pixel / 8));
	mlx->process(mlx);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->image, 0, 0);
	mlx_string_put(mlx->init, mlx->win, 20, 20, 0xFFFFFF, "topkoek lol");
	return (0);
}

/*
**	Check what Fractol needs to be drawn.
**	Error if Fractol does not exist and list other fractols as error.
*/

void		check_fractol(char *fractol_name, t_mlx *mlx)
{
	if (ft_strcmp(fractol_name, "Mandelbrot") == 0 || ft_strcmp(fractol_name, "mandelbrot") == 0)
		mlx->process = &process_mandelbrot;
	else if (ft_strcmp(fractol_name, "Julia") == 0 || ft_strcmp(fractol_name, "julia") == 0)
		mlx->process = &process_julia;
	else
		no_fractol();
}

void		fractol(char *fractol_name)
{
	t_mlx	*mlx;

	mlx = init_window(fractol_name);
	check_fractol(fractol_name, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, deal_key, mlx);
	if (ft_strcmp(fractol_name, "Julia") == 0 || ft_strcmp(fractol_name, "julia") == 0)
	{
		mlx_hook(mlx->win, 6, 1L << 8, deal_move, mlx);
		mlx_hook(mlx->win, 5, 1L << 3, mouse_release, mlx);
	}
	mlx_hook(mlx->win, 4, 1L << 2, deal_mouse, mlx);
	mlx_loop_hook(mlx->init, process_fract, mlx);
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
