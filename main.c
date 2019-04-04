/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:01:26 by nvreeke        #+#    #+#                */
/*   Updated: 2019/04/04 15:53:04 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Initialize program function & values
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
	mlx->space = 0;
	mlx->first_boot = 0;
	mlx->fractol_name = fractol_name;
	return (mlx);
}

/*
**	Check what Fractol needs to be drawn.
**	Error if Fractol does not exist and list other fractols as error.
*/

void		check_fractol(t_mlx *mlx)
{
	if (!(mlx->first_boot))
	{
		mlx->first_boot = 1;
		if (ft_strcmp(mlx->fractol_name, "-man") == 0)
		{
			mlx->process = &process_mandelbrot;
			mlx->space = 0;
		}
		else if (ft_strcmp(mlx->fractol_name, "-jul") == 0)
		{
			mlx->process = &process_julia;
			mlx->space = 1;
			mlx_hook(mlx->win, 6, 1L << 8, deal_move, mlx);
		}
		else if (ft_strcmp(mlx->fractol_name, "-bur") == 0)
		{
			mlx->process = &process_burningship;
			mlx->space = 2;
		}
		else
			no_fractol();
	}
	else if (mlx->first_boot)
	{
		if (mlx->space == 0)
			mlx->process = &process_mandelbrot;
		else if (mlx->space == 1)
		{
			mlx->process = &process_julia;
			mlx_hook(mlx->win, 6, 1L << 8, deal_move, mlx);
		}
		else if (mlx->space == 2)
			mlx->process = &process_burningship;
	}
}

/*
**	Clears image with bzero, runs draw fractol function and puts new image to window.
*/

int			process_fract(t_mlx *mlx)
{
	ft_bzero(mlx->data_addr, HEIGHT * WIDTH * (mlx->bits_per_pixel / 8));
	mlx->process(mlx);
	check_fractol(mlx);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->image, 0, 0);
	mlx_string_put(mlx->init, mlx->win, 20, 20, 0xFFFFFF, "Zoom in/out: Mousewheel");
	mlx_string_put(mlx->init, mlx->win, 20, 35, 0xFFFFFF, "Move fractal: Arrow keys");
	mlx_string_put(mlx->init, mlx->win, 20, 50, 0xFFFFFF, "Change color: Tab");
	mlx_string_put(mlx->init, mlx->win, 20, 65, 0xFFFFFF, "Change fractal: Space");
	mlx_string_put(mlx->init, mlx->win, 20, 80, 0xFFFFFF, "Decrease/increase detail: z/x");
	mlx_string_put(mlx->init, mlx->win, 20, 95, 0xFFFFFF, "Exit: Esc");
	return (0);
}

void		fractol(char *fractol_name)
{
	t_mlx	*mlx;

	mlx = init_window(fractol_name);
	check_fractol(mlx);
	mlx_hook(mlx->win, 2, 1L << 0, deal_key, mlx);
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
