/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:03:10 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/22 14:19:38 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

void			init_window(void);

/*
**	Error handlers
*/

void			no_params(void);

/*
**	Error handlers
*/

int				deal_key(int key);