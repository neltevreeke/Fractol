/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:03:10 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/29 13:04:40 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "minilibx_macos/mlx.h"
#include "libft/libft.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

# define HEIGHT 600
# define WIDTH	1000
# define MEM(x) (x*)ft_memalloc(sizeof(x))
# define NUM_THREADS 100

/*
**	Int key defines
*/

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_X 7
# define KEY_Z 6
# define KEY_TAB 48

/*
**	Int mouse defines
*/

# define MOUSE_UP 4
# define MOUSE_DOWN 5

typedef struct s_point
{
	long double x;
	long double y;
}				t_point;


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

	t_point		position;
	t_point		c;
	int			max_it;
	long double	zoom;

	/*
	**	color stuff
	*/

	int			tab;

	/*
	**	Pthread stuff
	*/

	int			cur_y;
	int			max_y;
	
	void		(*process)(struct s_mlx *mlx);
}				t_mlx;

/*
**	Color functions
*/

int				c_pallette(int n, t_point z, t_mlx *mlx);

/*
**	Fractol functions
*/

int				process_fract(t_mlx *mlx);

/*
**	Pthread functions
*/

void			process_mandelbrot(t_mlx *mlx);

/*
**	Error handlers
*/

void			no_params(void);
void			no_fractol(void);

/*
**	Event (key, mouse) handlers
*/

int				deal_key(int key, t_mlx *mlx);
int				deal_mouse(int button, int x, int y, t_mlx *mlx);

#endif
