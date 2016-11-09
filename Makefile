# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/13 17:53:01 by gpinchon          #+#    #+#              #
#    Updated: 2016/11/09 22:57:02 by gpinchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libvml.a
SRC		=	./src/mat/init.c			\
			./src/mat/convert.c			\
			./src/mat/operations.c		\
			./src/mat/mult.c			\
			./src/mat/new.c				\
			./src/mat/creation.c		\
			./src/mat/projection.c		\
			./src/vec/new.c				\
			./src/vec/div.c				\
			./src/vec/proj.c			\
			./src/vec/add.c				\
			./src/vec/cross.c			\
			./src/vec/dot.c				\
			./src/vec/length.c			\
			./src/vec/negate.c			\
			./src/vec/normalize.c		\
			./src/vec/sub.c				\
			./src/vec/convert.c			\
			./src/vec/mult.c			\
			./src/vec/scale.c			\
			./src/vec/interp.c			\
			./src/ray/new.c				\
			./src/ray/calc.c			\
			./src/ray/primitives.c		\
			./src/ray/primitives2.c		\
			./src/ray/normals.c			\
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