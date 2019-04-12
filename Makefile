# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nvreeke <nvreeke@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/22 13:27:36 by nvreeke        #+#    #+#                 #
#    Updated: 2019/04/11 11:32:01 by nvreeke       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

BINARY = fractol
SRCS = ./src/burningship.c ./src/check_fractol.c ./src/errors.c ./src/event_handlers.c \
./src/julia.c ./src/main.c ./src/mandelbrot.c ./src/palette.c ./src/utils.c
OBJ = $(SRCS:%.c=%.o)
FLAGS = -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -o $(BINARY)
ERRFLAGS = -Wall -Wextra -Werror
GCC = gcc
LIBS = ./libft/libft.a

all: $(BINARY)

$(BINARY):
	@echo "Compiling..."
	@make -C minilibx_macos re > /dev/null
	@make -C libft re > /dev/null
	@$(GCC) $(SRCS) $(INC) -I/usr/X11/includes $(FLAGS) $(ERRFLAGS) $(LIBS) -o $(BINARY)
	@echo "Done"

clean:
	@echo "Removing object files"
	@make -C minilibx_macos clean > /dev/null
	@make -C libft clean > /dev/null
	@rm -rf $(OBJ)
	@echo "Done"

fclean: clean
	@echo "Removing binary and extraneous directories"
	@make -C libft fclean > /dev/null
	@rm -rf fractol.dSYM
	@rm -rf $(BINARY)
	@echo "Done"

re: fclean all
