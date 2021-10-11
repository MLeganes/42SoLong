# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 11:24:29 by amorcill          #+#    #+#              #
#    Updated: 2021/10/11 16:04:28 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
OBJS	= $(patsubst %.c, %.o, $(SRCS))
SRCS	= solong_main.c \
		  solong_event_keys.c

all: $(NAME)

# LINKING
$(NAME): libft libmlx $(OBJS)
	$(CC) -Llibmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)
#	make -C Libft all
# -L LIBRARY location of the libmlx => Llibmlx
# -l (for lib) libmlx	(remove lib) => lmlx

# COMPILING
%.o: %.c	
	$(CC) $(FLAGS)  -Ilibmlx -Ilibft -c $< -o $@

# ILibft  for include the Libft.
# Imlx  for include the mlx.

clean:
	rm -f *.o
	rm -f *.out
	make -C libmlx clean
	make -C libft clean

fclean: clean
	make -C libft fclean	
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: libft
libft:
	make -C libft all

.PHONY: libmlx
mlx:
	make -C libmlx all

### References
# https://makefiletutorial.com/
# https://opensource.com/article/18/8/what-how-makefile

### make commands!!!
#		make -n => to see all the steeps

#### To avoid warnings
#%.o : %.c 
#    @cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<
#%.o : %.m
#    @cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<