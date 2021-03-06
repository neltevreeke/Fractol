/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   palette.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:09:09 by nvreeke        #+#    #+#                */
/*   Updated: 2019/04/08 14:11:29 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Calculation needed to calculate the brightness (opacity) of the pixel.
*/

double		dot_product(t_point p)
{
	return (p.x * p.x + p.y * p.y);
}

/*
**	Colors the pixels in the screen
*/

void		put_pixel_to_img(t_mlx *mlx, int x, int y, int color)
{
	int i;

	i = (y * WIDTH + x) * 4;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		mlx->data_addr[i] = color;
		i++;
		mlx->data_addr[i] = color >> 8;
		i++;
		mlx->data_addr[i] = color >> 16;
		i++;
	}
}

/*
**	Manipulates colors.
*/

int			*manipulate_pallette(int *color, int bright, t_mlx *mlx)
{
	if (mlx->tab == 0)
	{
		color[0] = sqrt(bright);
		color[2] = sqrt(bright);
	}
	else if (mlx->tab == 1)
		color[0] = sqrt(bright);
	else if (mlx->tab == 2)
	{
		color[1] = sqrt(bright);
		color[2] = sqrt(bright);
	}
	else if (mlx->tab == 3)
		color[1] = sqrt(bright);
	else if (mlx->tab == 4)
		color[2] = sqrt(bright);
	else if (mlx->tab == 5)
	{
		color[0] = sqrt(bright);
		color[1] = sqrt(bright);
	}
	return (color);
}

/*
**	Creates, calculates.
*/

int			c_pallette(int n, t_point z, t_mlx *mlx)
{
	double	bright;
	int		color[3];

	bright = n - log2(log2(dot_product(z))) + 4.0;
	color[0] = 255 * (bright / mlx->max_it);
	color[1] = 255 * (bright / mlx->max_it);
	color[2] = 255 * (bright / mlx->max_it);
	manipulate_pallette(color, bright, mlx);
	return (color[0] | (color[1] << 8) | (color[2] << 16));
}
