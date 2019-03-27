/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   palette.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:09:09 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/27 18:09:07 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		dot_product(t_point p)
{
	return (p.x * p.x + p.y * p.y);
}

long		map(long x, long in_min, long in_max, long out_min, long out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int		c_pallette(double n, t_point z, t_mlx *mlx)
{
	int bright;
	int red;
	int blue;
	int green;

	bright = map(n, 0, mlx->max_it, 0, 255);
	red = map(bright * bright, 0, 255 * 255, 0, 255);
	blue = map(sqrt(bright), 0, sqrt(255), 0, 255);
	green = bright;
	if (n == mlx->max_it || bright < 40)
		bright = 0;
	return (red);
}
