# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nvreeke <nvreeke@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/22 13:27:36 by nvreeke        #+#    #+#                 #
#    Updated: 2019/04/09 17:39:11 by nvreeke       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

BINARY = fractol
SRCS = burningship.c check_fractol.c errors.c event_handlers.c \
julia.c main.c mandelbrot.c palette.c utils.c
OBJ = $(SRCS:.c=*.o)
FLAGS = -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -o $(BINARY)
GCC = gcc
LIBS = ./libft/libft.a

all: $(BINARY)

$(BINARY):
	@echo "Compiling..."
	@make -C minilibx_macos re > /dev/null
	@$(GCC) -g $(SRCS) -I/usr/X11/includes $(FLAGS) $(LIBS)
	@echo "Done"

clean:
	@echo "Removing object files"
	@make -C minilibx_macos clean > /dev/null
	@rm -rf $(OBJ)
	@echo "Done"

fclean: clean
	@echo "Removing binary and extraneous directories"
	@rm -rf fractol.dSYM
	@rm -rf $(BINARY)
	@echo "Done"

re: fclean all
