/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event_handlers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 14:18:18 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/29 13:52:39 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Deals with key events
*/

int		deal_key(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_UP)
		mlx->position.y += 0.05 * mlx->zoom;
	if (key == KEY_DOWN)
		mlx->position.y -= 0.05 * mlx->zoom;
	if (key == KEY_LEFT)
		mlx->position.x += 0.05 * mlx->zoom;
	if (key == KEY_RIGHT)
		mlx->position.x -= 0.05 * mlx->zoom;
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
	return (0);
}

/*
**	Deals with mouse events
*/

int		deal_mouse(int button, int x, int y, t_mlx *mlx)
{
	if (button == MOUSE_DOWN)
		mlx->zoom *= 1.05;
	if (button == MOUSE_UP)
		mlx->zoom *= 0.95;
	return (0);
}
