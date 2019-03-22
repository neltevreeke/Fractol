/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event_handlers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 14:18:18 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/22 14:19:48 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		deal_key(int key)
{
	if (key == KEY_ESC)
		exit(0);
	return (0);
}