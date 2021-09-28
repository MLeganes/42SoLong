# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 11:24:29 by amorcill          #+#    #+#              #
#    Updated: 2021/09/28 14:01:09 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = main.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

# Runing 1 place LINKING
$(NAME): libft mlx $(OBJS)
	$(CC) -Lmlx -lmlx -LLibft -lft -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)
#	make -C Libft all

# -L LIBRARY location of the mlx => Lmlx
# -l libmlx	(remove lib) => lmlx

 .PHONY: libft
libft:
	make -C Libft all

.PHONY: mlx
mlx:
	make -C mlx all

# Runing 2 place COMPILING
%.o: %.c	
	$(CC) $(FLAGS)  -Imlx -ILibft -c $< -o $@

all: $(NAME)

clean:
	rm -f *.o
	rm -f *.out
	make -C mlx clean

fclean: clean
#	rm -rf ./Libft/*.o
	make -C Libft fclean	
	rm -f $(NAME)

re: fclean $(NAME)
         

# https://makefiletutorial.com/
# https://opensource.com/article/18/8/what-how-makefile

# make commands
#		make -n => to see all the steeps

	