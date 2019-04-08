/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:01:26 by nvreeke        #+#    #+#                */
/*   Updated: 2019/04/08 14:05:06 by nvreeke       ########   odam.nl         */
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
	mlx->data_addr = mlx_get_data_addr(mlx->image, &(mlx->bits_per_pixel), \
	&(mlx->size_line), &(mlx->endian));
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
**	Clears image with bzero
**	runs draw fractol function and puts new image to window.
*/

int			process_fract(t_mlx *mlx)
{
	ft_bzero(mlx->data_addr, HEIGHT * WIDTH * (mlx->bits_per_pixel / 8));
	mlx->process(mlx);
	check_fractol(mlx);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->image, 0, 0);
	mlx_string_put(mlx->init, mlx->win, 20, 20, 0xFFFFFF, \
	"Zoom in/out: Mousewheel");
	mlx_string_put(mlx->init, mlx->win, 20, 35, 0xFFFFFF, \
	"Move fractal: Arrow keys");
	mlx_string_put(mlx->init, mlx->win, 20, 50, 0xFFFFFF, \
	"Change color: Tab");
	mlx_string_put(mlx->init, mlx->win, 20, 65, 0xFFFFFF, \
	"Change fractal: Space");
	mlx_string_put(mlx->init, mlx->win, 20, 80, 0xFFFFFF, \
	"Decrease/increase detail: z/x");
	mlx_string_put(mlx->init, mlx->win, 20, 95, 0xFFFFFF, \
	"Exit: Esc");
	return (0);
}

/*
**	Starts the key and mouse hooks.
**	Initiates fractol function.
*/

void		fractol(char *fractol_name)
{
	t_mlx	*mlx;

	mlx = init_window(fractol_name);
	check_fractol(mlx);
	mlx_hook(mlx->win, 4, 1L << 2, deal_mouse, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, deal_key, mlx);
	mlx_loop_hook(mlx->init, process_fract, mlx);
	mlx_loop(mlx->init);
}

/*
**	Checks number of arguments.
**	intiates fractal program.
*/

int			main(int argc, char **argv)
{
	if (argc <= 1)
		no_params();
	else
		fractol(argv[1]);
	return (0);
}
