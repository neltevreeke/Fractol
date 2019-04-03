# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nvreeke <nvreeke@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/22 13:27:36 by nvreeke        #+#    #+#                 #
#    Updated: 2019/04/03 12:38:10 by nvreeke       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

BINARY = fractol
SRCS = *.c
FLAGS = -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -o $(BINARY)
GCC = gcc
LIBS = ./libft/libft.a

all: $(BINARY)

$(BINARY):
	@echo "Compiling..."
	make -C minilibx_macos re
	@$(GCC) -g $(SRCS) -I/usr/X11/includes $(FLAGS) $(LIBS)
	@echo "Done"

clean:
	@echo "Removing object files"
	@rm -rf *.o

fclean: clean
	@echo "Removing binary"
	@rm -rf $(BINARY)

re: fclean all
