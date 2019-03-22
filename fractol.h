/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:03:10 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/22 15:11:15 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "minilibx_macos/mlx.h"
#include "libft/libft.h"
#include <math.h>
#include <stdlib.h>

# define HEIGHT 1000
# define WIDTH	1000
# define MEM(x) (x*)ft_memalloc(sizeof(x))

/*
**	Int key defines
*/

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_DOWN 125

typedef	struct	s_mlx
{
	/*
	**	Program pointers
	*/

	void		*win;
	void		*init;
	
	/*
	**	Image stuff
	*/

	void		*image;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_mlx;

/*
**	Initializers
*/

// void			init_window(void);

/*
**	Error handlers
*/

void			no_params(void);

/*
**	Event (key, mouse) handlers
*/

int				deal_key(int key);

#endif