/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:18:59 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/22 15:27:46 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <math.h>
# include "libmlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

/*
 Defines for the width and height of your window. I suggest you to do the same so
 you can change easily the size of your window later if needed.
*/
# define WIN_MAX_HEIGHT 1440
# define WIN_MAX_WIDTH 2560
# define ZOOM 64

# define PLAYER_DIR_A 1
# define PLAYER_DIR_S 2
# define PLAYER_DIR_D 3
# define PLAYER_DIR_W 4
# define IMG_EXIT 0
# define IMG_PATH_1 1
# define IMG_PATH_2 2
# define IMG_WALL 3
# define IMG_COLLECT 4
# define IMG_PLAY_A 5
# define IMG_PLAY_W 6
# define IMG_PLAY_D 7
# define IMG_PLAY_S 8
# define IMG_PINK 9
# define IMG_MAX 10

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}			t_img;

typedef struct s_player
{
	int			dir;
	int			printed;
	int			horizontal;
	int			vertical;
	int			new_x;
	int			new_y;
	int			steps;
	int			collects;
	int			lives;
	int			game_on;
}				t_player;

typedef struct s_ghost
{
	int			x;
	int			y;
	int			new_x;
	int			new_y;
}				t_ghost;

typedef struct s_map
{
	int			players;
	int			collectibles;
	int			ghost;
	int			exit;
	int			height;
	int			width;
}				t_map;

typedef struct s_mlx
{
	char		*name;
	void		*mlx;
	void		*win;
	char		**map;
	int			bonus;
	int			ghost_id;
	t_map		imap;	
	t_img		imgs[10];
	t_player	player1;
	t_ghost		ghost[10];
}				t_mlx;

/*
 * Solong main init
 */
void	main_init_mlx(t_mlx *mlx);
void	main_load_map(t_mlx *mlx, char **argv);
void	main_load_image_map(t_mlx *mlx);
void	main_load_image_player(t_mlx *mlx);
/*
 * Solong events
 */
int		key_events(int key, t_mlx *mlx);
/*
 * Solong player
 */
void	player_move_a(t_mlx *mlx);
void	player_move_s(t_mlx *mlx);
void	player_move_d(t_mlx *mlx);
void	player_move_w(t_mlx *mlx);
void	player_update(t_mlx *mlx);
/*
 * Solong map load
 */
void	map_load_path1(t_mlx *mlx, int w, int h);
void	map_load_path2(t_mlx *mlx, int w, int h);
void	map_load_wall(t_mlx *mlx, int w, int h);
void	map_load_player(t_mlx *mlx, int w, int h);
void	map_load_init_player(t_mlx *mlx, int w, int h);
/*
 * Solong map
 */
void	map_check(t_mlx *mlx);
void	map_update_path(t_mlx *mlx, int x, int y);
void	map_update_player(t_mlx *mlx, int x, int y);
void	map_valic_characters(t_mlx *mlx, char *s, int i);
/*
 * Solong collectible 
 */
void	collectible_load(t_mlx *mlx, int w, int h);
void	collectible_increase(t_mlx *mlx);
int		collectible_check(t_mlx *mlx);
void	collectible_decrease(t_mlx *mlx);
/*
 * Solong error 
 */
void	error_print_exit(char *error_msg);
/*
 * Solong exit 
 */
void	exit_load(t_mlx *mlx, int w, int h);
int		exit_game(t_mlx *mlx);
void	game_win(t_mlx *mlx);
/*
 * Solong resize
 */
void	resize_img(t_mlx *mlx);
void	ft_copy_px(t_img *data, int x, int y, int color);
void	ft_create_img(t_img *newimg, t_img *oldimg, int scale);
void	ft_maximum_screen(t_mlx *mlx);
/*
 * Solong utils
 */
void	ft_remove_eol(char *s);
void	ft_check_emptyline(char *line);
void	ft_count_lines(t_mlx *mlx, char **argv);
/*
 * Solong score
 */
void	score_print(t_mlx *mlx);
void	score_steps(t_mlx *mlx);
void	score_collectibles(t_mlx *mlx);
/*
 * Solong BONUS
 */
void	init_load_ghost(t_mlx *mlx, int x, int y);
void	load_image_ghost(t_mlx *mlx);
void	load_ghost(t_mlx *mlx, int x, int y);
int		ghost_move(t_mlx *mlx);
int		ghost_check(t_mlx *mlx, int x, int y);
void	ghost_move_secondpart(t_mlx *mlx, int x, int y);
void	ft_move_ramdom(t_mlx *mlx);
void	ghost_update(t_mlx *mlx, int x, int y);
void	ghost_player_crash(t_mlx *mlx, int x, int y);
void	game_over(t_mlx *mlx);
#endif
