/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_fractol.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 12:35:07 by nvreeke        #+#    #+#                */
/*   Updated: 2019/04/08 12:35:15 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	check_fractol_boot(mlx);
}

/*
**	Checks if the program has been booted already.
**	Checks what fractal needs to be drawn.
*/

void		check_fractol_boot(t_mlx *mlx)
{
	if (mlx->first_boot)
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
