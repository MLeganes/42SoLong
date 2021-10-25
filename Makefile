# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 11:24:29 by amorcill          #+#    #+#              #
#    Updated: 2021/10/25 18:04:37 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
NAME_LK	= so_long_leaks
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
SNTZ	= -g -fsanitize=address
OBJS	= $(patsubst %.c, %.o, $(SRCS))
SRCS	= solong_main.c \
		  solong_init.c \
		  solong_key_events.c \
		  solong_map.c \
		  solong_player.c \
		  solong_exit.c \
		  solong_collectible.c \
		  solong_error.c \
		  solong_utils.c \

# COMPILING
%.o: %.c	
ifeq ($(MAKECMDGOALS), $(NAME))
	$(CC) $(FLAGS) -Ilibmlx -Ilibft -c $< -o $@
else
	$(CC) $(SNTZ) $(FLAGS) -Ilibmlx -Ilibft -c $< -o $@
endif

# LINKING
all: $(NAME)

$(NAME): makelibft makelibmlx $(OBJS)
	$(CC) $(SNTZ) -Llibmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)
#	make -C Libft all
# -L LIBRARY location of the libmlx => Llibmlx
# -l (for lib) libmlx	(remove lib) => lmlx

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
	./so_long ./game_levels/level051.ber

makelibft:
	make -C libft all

makelibmlx:
	make -C libmlx all

# LINKING LEAKS
all: $(NAME_LK)

$(NAME_LK): makelibft makelibmlx $(OBJS)
	$(CC) $(SNTZ) -Llibmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME_LK) $(OBJS) 
	
relk: fclean $(NAME_LK)

runlk:
	./so_long_leaks ./game_levels/level051.ber


#### To avoid warnings
#%.o : %.c 
#    @cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<
#%.o : %.m
#    @cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<

# ILibft  for include the Libft.
# Imlx  for include the mlx.

### References
#		https://makefiletutorial.com/
#		https://opensource.com/article/18/8/what-how-makefile

### make commands
#		make -n => to see all the steeps