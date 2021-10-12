#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
//# include <mlx.h>
//# include <libft.h>
# include "libmlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>


// To change with my ftlib
#include <stdio.h>

//https://github.com/keuhdall/images_example





/*
 Defines for the width and height of your window. I suggest you to do the same so
 you can change easily the size of your window later if needed.
*/
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define EVENT_KEY_PRESS 2
# define MASK_KEY_PRESS 1L<<2

typedef struct	s_mlx
{
	char		*name;
	void		*mlx;
	void		*win;
	char		**map;

	int			player1_horizontal;
	int			player1_vertical;

	
	int			endian;
	void		*img;
	int			*img_data; 
	int			img_size_l;
	int			img_bpp;
	int			img_width;
	int			img_height;

	void		*pointer_path;
	void		*pointer_wall;
	void		*pointer_player1;
	void		*pointer_exit;
	void		*pointer_collect;

	char		*relative_path_path;
	char		*relative_path_wall;
	char		*relative_path_player1;
	char		*relative_path_exit;
	char		*relative_path_collect;

	int			x;
	int			y;
}				t_mlx;


int key_events(int key, t_mlx *mlx);

int player_move_a(t_mlx *mlx);
int player_move_s(t_mlx *mlx);
int player_move_d(t_mlx *mlx);
int player_move_w(t_mlx *mlx);

void map_update_position(t_mlx *mlx, int hei, int wid);

#endif