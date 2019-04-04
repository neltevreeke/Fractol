/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event_handlers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 14:18:18 by nvreeke        #+#    #+#                */
/*   Updated: 2019/04/04 15:48:19 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Deals with Julia & mandelbrot key events
*/

int		deal_key(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_UP)
		mlx->position.y -= 0.05 * mlx->zoom;
	if (key == KEY_DOWN)
		mlx->position.y += 0.05 * mlx->zoom;
	if (key == KEY_LEFT)
		mlx->position.x -= 0.05 * mlx->zoom;
	if (key == KEY_RIGHT)
		mlx->position.x += 0.05 * mlx->zoom;
	if (key == KEY_X)
	{
		mlx->max_it += 5;
		if (mlx->max_it > 140)
			mlx->max_it = 140;
	}
	if (key == KEY_Z)
	{
		mlx->max_it -= 5;
		if (mlx->max_it < 15)
			mlx->max_it = 15;
	}
	if (key == KEY_TAB)
	{
		mlx->tab++;
		if (mlx->tab > 5)
			mlx->tab = 0;
	}
	if (key == KEY_SPACE)
		mlx->space++;
		if (mlx->space > 2)
			mlx->space = 0;
	return (0);
}

/*
**	Deals with julia & mandelbrot mouse events
*/

int		deal_mouse(int button, int x, int y, t_mlx *mlx)
{
	if (button == MOUSE_DOWN)
		mlx->zoom *= 1.05;
	if (button == MOUSE_UP)
		mlx->zoom *= 0.95;
	if (button == MOUSE_LEFT && mlx->button == 0)
		mlx->button = 1;
	else if (button == MOUSE_LEFT && mlx->button == 1)
		mlx->button = 0;
	return (0);
}

/*
** Deals ONLY with julia mouse event
*/

int		deal_move(int x, int y, t_mlx *mlx)
{
	if (mlx->button == 0)
	{
		mlx->c.x = x * 2;
		mlx->c.y = y * 2 - 600;
	}
	return (0);
}
