# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 11:24:29 by amorcill          #+#    #+#              #
#    Updated: 2021/09/27 18:00:43 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = main.c

OBJ = main.o

# Runing 1 place 
$(NAME): libft *.c
	$(CC) -Lmlx -lmlx -LLibft -lft -framework OpenGL -framework AppKit -o $(NAME) $(SRCS)
#	make -C Libft all

# -L location of the mlx => Lmlx
# -l libmlx	(remove lib) => lmlx

 .PHONY: libft
libft:
	make -C Libft all

# Runing 2 place
.PHONY: %.o
%.o: %.c	
	$(CC) $(FLAGS)  -Imlx -c $< -o $@

all: $(NAME)

clean:
	rm -f *.o
	rm -f *.out

fclean: clean
	rm -rf ./Libft/*.o
	rm -f $(NAME)

re: fclean $(NAME)
         

# https://makefiletutorial.com/
# https://opensource.com/article/18/8/what-how-makefile

# make commands
#		make -n => to see all the steeps

	