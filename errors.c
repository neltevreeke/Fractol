/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:06:19 by nvreeke        #+#    #+#                */
/*   Updated: 2019/04/08 13:59:15 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Puts error on the output if there are no parameters given.
*/

void	no_params(void)
{
	ft_putendl("Usage: ./fractol [fractolname]");
	exit(0);
}

/*
**	Puts error on the output if there are no valid fractals given.
*/

void	no_fractol(void)
{
	ft_putendl("Usage: ./fractol [fractolname]");
	ft_putendl("Try:\t\t -man");
	ft_putendl("\t\t -jul");
	ft_putendl("\t\t -bur");
	exit(0);
}
