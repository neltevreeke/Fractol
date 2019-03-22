/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:01:26 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/22 14:18:10 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_window(void)
{
	t_mlx *mlx;

	mlx = MEM(t_mlx);
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, "Parkeergarage Geen Plek");
	mlx->image = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	mlx->data_addr = mlx_get_data_addr(mlx->image, &(mlx->bits_per_pixel), &(mlx->size_line), &(mlx->endian));

	mlx_hook(mlx->win, 2, 1L<< 0, deal_key, mlx);
	mlx_loop(mlx->init);
}

int		main(int argc, char **argv)
{
	if (argc <= 1)
		no_params();
	else
		init_window();
	return (0);
}
