/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   palette.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:09:09 by nvreeke        #+#    #+#                */
/*   Updated: 2019/04/03 12:33:28 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		dot_product(t_point p)
{
	return (p.x * p.x + p.y * p.y);
}


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
	//----------------------------------- groen
		//geel
			// color[0] = sqrt(bright);
		
		// color[2] = sqrt(bright);
		
	// blauw
		// magenta
			// color[1] = sqrt(bright);

		// cyan
			// color[2] = sqrt(bright);

	// rood
		// color[0] = sqrt(bright);
		// color[1] = sqrt(bright);

	return (color[0] | (color[1] << 8) | (color[2] << 16));
}
