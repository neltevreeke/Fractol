/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:06:19 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/22 12:09:45 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	no_params(void)
{
	ft_putendl("Usage: ./fractol [fractolname]");
	exit(0);
}
