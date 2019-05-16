# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 16:01:39 by hcasanov          #+#    #+#              #
#    Updated: 2019/05/13 16:01:42 by hcasanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol

CC = gcc

FLAG = -Wall -Werror -Wextra

FLAG_LIBX = -lmlx -framework OpenGL -framework AppKit

SRC =  burningship.c fractal.c image.c julia.c main.c mandelbrot.c \
tools.c init.c

SRC_DIR = src/

SRCS = $(addprefix $(SRC_DIR), $(SRC))

LIB_PATH = libft/

LIB = libft/libft.a

LIB_INC = libft/

INC_PATH = include/

INC = include/fractol.h

OBJ = $(SRC:.c=.o)

RED = \033[91m
GREEN = \033[92m
BLUE = \033[96m
YEL = \033[93m
BL = \033[0m
MAG = \033[35m

.PHONY : all, re, clean, fclean, lib

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@$(CC) $(FLAG) -o $(NAME) $(OBJ) $(LIB) $(FLAG_LIBX)
	@echo "          $(RED)< Compilation Done ! >$(BL)"

$(LIB):
	@make -C $(LIB_PATH)

%.o: $(SRC_DIR)%.c $(INC)
	@$(CC) $(FLAG) -c $< -o $@ -I$(INC_PATH) -I$(LIB_INC)

clean:
	@rm -rf $(OBJ)
	@echo "          $(RED)< Clean Done >$(BL)           "

fclean: clean
	@rm -rf $(NAME)
	@echo "          $(RED)< Programme Fdf Deleted >$(BL)"

re: fclean all

lib:
	@make re -C $(LIB_PATH)