/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:18:59 by x250              #+#    #+#             */
/*   Updated: 2021/11/04 10:37:05 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <math.h>
# include "libmlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
//https://github.com/keuhdall/images_example

/*
 Defines for the width and height of your window. I suggest you to do the same so
 you can change easily the size of your window later if needed.
*/
# define WIN_MAX_HEIGHT 1080
# define WIN_MAX_WIDTH 1920
# define ZOOM 64

// # define EVENT_KEY_PRESS 2
// # define EVENT_KEY_DESTROYNOTIFY 17
// # define MASK_KEY_PRESS 1L<<2
// # define MASK_KEY_STRUCTURENOTIFY 1L<<17
//# define EXIT_GAME 0

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
 * Solong init
 */
void	main_init_mlx(t_mlx *mlx);
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
 * Solong map
 */
void	map_check(t_mlx *mlx);
void	map_update_path(t_mlx *mlx, int x, int y);
void	map_update_player(t_mlx *mlx, int x, int y);
/*
 * Solong collectible 
 */
void	collectible_increase(t_mlx *mlx);
int		collectible_check(t_mlx *mlx);
void	collectible_decrease(t_mlx *mlx);
/*
 * Solong error 
 */
void	error_print_exit(char *error_msg);
int		exit_game(t_mlx *mlx);
/*
 * Solong resize
 */
void	resize_img(t_mlx *mlx);
void	ft_copy_px(t_img *data, int x, int y, int color);
void	ft_create_img(t_img *newimg, t_img *oldimg, int scale);
/*
 * Solong utils
 */
void	ft_remove_eol(char *s);
int		ft_count_lines(t_mlx *mlx, char **argv);
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
int		ghost_move(t_mlx *mlx);
int		ghost_check(t_mlx *mlx, int x, int y);
void	ghost_move_secondpart(t_mlx *mlx, int x, int y);
void	ft_move_ramdom(t_mlx *mlx);
void	ghost_update(t_mlx *mlx, int x, int y);
void	ghost_player_crash(t_mlx *mlx, int x, int y);
void	game_over(t_mlx *mlx);
#endif
