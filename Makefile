# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 11:24:29 by amorcill          #+#    #+#              #
#    Updated: 2021/11/16 13:00:28 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
OBJS	= $(patsubst %.c, %.o, $(SRCS))
SRCS	= solong_main.c \
		  solong_main_load.c \
		  solong_init.c \
		  solong_key_events.c \
		  solong_map.c \
		  solong_map_check.c \
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

BONUS	= 0
 
%.o: %.c
	$(CC) $(FLAGS) -Ilibmlx -Ilibft -D BONUS=$(BONUS) -c $< -o $@

all: $(NAME)

$(NAME): libft/libft.a libmlx/libmlx.a $(OBJS)
	$(CC) -Llibmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)

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

bonus: BONUS=1
bonus: fclean all
		
libft/libft.a:
	make -C libft all

libmlx/libmlx.a:
	make -C libmlx all