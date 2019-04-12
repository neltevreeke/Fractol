/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:03:10 by nvreeke        #+#    #+#                */
/*   Updated: 2019/04/11 11:18:37 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define HEIGHT 600
# define WIDTH	1000
# define MEM(x) (x*)ft_memalloc(sizeof(x))
# define NUM_THREADS 10

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
# define KEY_SPACE 49

/*
**	Int mouse defines
*/

# define MOUSE_LEFT 1
# define MOUSE_UP 4
# define MOUSE_DOWN 5

typedef struct	s_point
{
	long double x;
	long double y;
}				t_point;

typedef	struct	s_mlx
{
	void		*win;
	void		*init;
	void		*image;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_point		position;
	t_point		c;
	int			max_it;
	long double	zoom;
	int			tab;
	int			button;
	int			space;
	char		*fractol_name;
	int			first_boot;
	int			cur_y;
	int			max_y;
	void		(*process)(struct s_mlx *mlx);
}				t_mlx;

/*
**	Color functions
*/

int				c_pallette(int n, t_point z, t_mlx *mlx);
void			put_pixel_to_img(t_mlx *mlx, int x, int y, int color);

/*
**	Fractol functions
*/

int				process_fract(t_mlx *mlx);
void			check_fractol_boot(t_mlx *mlx);
void			check_fractol(t_mlx *mlx);

/*
**	UI functions
*/

void			put_ui(t_mlx *mlx);

/*
**	FPS meter functions
*/

char			*get_fps(char *str);
double			get_cur_time(void);

/*
**	Pthread functions
*/

void			process_mandelbrot(t_mlx *mlx);
void			process_julia(t_mlx *mlx);
void			process_burningship(t_mlx *mlx);

/*
**	Error handlers
*/

void			no_params(void);
void			no_fractol(void);

/*
**	Event (key, mouse) handlers
*/

int				exit_x(void *nul);
int				deal_key(int key, t_mlx *mlx);
int				deal_arrow(int key, t_mlx *mlx);
int				deal_mouse(int button, int x, int y, t_mlx *mlx);
int				deal_move(int x, int y, t_mlx *mlx);
int				mouse_press(int button, int x, int y, t_mlx *mlx);
int				mouse_release(int button, int x, int y, t_mlx *mlx);

#endif
