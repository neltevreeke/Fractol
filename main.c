/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:01:26 by nvreeke        #+#    #+#                */
/*   Updated: 2019/04/08 17:31:38 by nvreeke       ########   odam.nl         */
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


double		get_cur_time(void)
{
	double time_in_mill;
	struct timeval  tv;
	
	gettimeofday(&tv, NULL);
	time_in_mill = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return(time_in_mill);
}

char		*get_fps(char *str)
{
	static double	start_time;
	static int		frames;
	static int		last_fps;

	frames++;
	if (get_cur_time() > start_time + 1000)
	{
		start_time = get_cur_time();
		last_fps = frames;
		frames = 0;
	}
	str = ft_itoa(last_fps);
	return(str);
}

int			process_fract(t_mlx *mlx)
{
	char	*str;

	str = get_fps(str);
	ft_bzero(mlx->data_addr, HEIGHT * WIDTH * (mlx->bits_per_pixel / 8));
	mlx->process(mlx);
	check_fractol(mlx);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->image, 0, 0);
	mlx_string_put(mlx->init, mlx->win, 960, 20, 0xFFFFFF, \
	str);
	free(str);
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
	mlx_hook(mlx->win, 17, 1L<<19, exit_x, NULL);
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
