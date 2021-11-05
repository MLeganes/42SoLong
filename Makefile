# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 11:24:29 by amorcill          #+#    #+#              #
#    Updated: 2021/11/05 14:20:20 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
SNTZ	= -fsanitize=address -fno-omit-frame-pointer  -static-libsan
#SNTZ	= 
OBJS	= $(patsubst %.c, %.o, $(SRCS))
SRCS	= solong_main.c \
		  solong_main_load.c \
		  solong_init.c \
		  solong_key_events.c \
		  solong_map.c \
		  solong_map_load.c \
		  solong_player.c \
		  solong_exit.c \
		  solong_collectible.c \
		  solong_error.c \
		  solong_resize.c \
		  solong_utils.c \
		  solong_score.c \
		  solong_bonus.c \
		  solong_load_bonus.c \
  

%.o: %.c
	$(CC) $(SNTZ) $(FLAGS) -Ilibmlx -Ilibft -D BONUS=0 -c $< -o $@

all: $(NAME)

$(NAME): makelibft makelibmlx $(OBJS)
	$(CC) $(SNTZ) -Llibmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)

clean:
	rm -f *.o
	rm -f *.out
	make -C libmlx clean
	make -C libft clean

fclean: clean
	make -C libft fclean	
	rm -f $(NAME)
	rm -f $(NAME_LK)

re: fclean $(NAME)

run:
	./so_long ./maps/pacman2.ber
		
makelibft:
	make -C libft all

makelibmlx:
	make -C libmlx all