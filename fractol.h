/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:03:10 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/22 13:03:20 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "libft/libft.h"
#include <math.h>

typedef	struct	s_mlx
{
	void		*win;
	void		*init;
}				t_mlx;

/*
**	Error handlers
*/

void			no_params(void);