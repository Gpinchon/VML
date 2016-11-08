# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/13 17:53:01 by gpinchon          #+#    #+#              #
#    Updated: 2016/11/08 17:20:45 by gpinchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libvml.a
SRC		=	./src/mat_init.c			\
			./src/mat_convert.c			\
			./src/mat_operations.c		\
			./src/mat_mult.c			\
			./src/mat_new.c				\
			./src/mat_creation.c		\
			./src/mat_projection.c		\
			./src/vec_init.c			\
			./src/vec_add.c				\
			./src/vec_cross.c			\
			./src/vec_dot.c				\
			./src/vec_length.c			\
			./src/vec_normalize.c		\
			./src/vec_sub.c				\
			./src/vec_convert.c			\
			./src/vec_mult.c			\
			./src/vec_scale.c			\
			./src/vec_interp.c			\
			./src/float_mult.c			\
			./src/interp_functions.c

OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Ofast -Wall -Wextra -Wall -I ./include


$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

NO_COLOR=\033[0m
OK_COLOR=\033[32;01m
OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)
%.o: %.c
	@echo -n Compiling $@...
	@($(CC) $(CFLAGS) -o $@ -c $<)
	@echo "$(OK_STRING)"

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)