/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   palette.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:09:09 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/28 15:13:09 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		dot_product(t_point p)
{
	return (p.x * p.x + p.y * p.y);
}

int			c_pallette(int n, t_point z, t_mlx *mlx)
{
	double	bright;
	int		color[3];

	bright = n - log2(log2(dot_product(z))) + 4.0;
	//blauw
	color[0] = 255 * (bright / mlx->max_it);
	//groen
	color[1] = 255 * (bright / mlx->max_it);
	//rood
	color[2] = 255 * (bright / mlx->max_it);

	// manupilates color
	//blauw
	// color[0] = sqrt(bright);
	// color[2] = sqrt(bright);

	return (color[0] | (color[1] << 8) | (color[2] << 16));
}
