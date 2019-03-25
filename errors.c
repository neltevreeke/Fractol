/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:06:19 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/25 11:30:20 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	no_params(void)
{
	ft_putendl("Usage: ./fractol [fractolname]");
	exit(0);
}

void	no_fractol(void)
{
	ft_putendl("This is not a correct Fractol, use: Mandelbrot, Juliet, or .....");
	exit(0);
}