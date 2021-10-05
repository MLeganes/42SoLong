#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include <mlx.h>
# include <libft.h>
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

typedef struct	s_mlx
{
	char		name;
	void		*mlx;
	void		*win;
	char		**map;
	
	int			endian;
	void		*img;
	int			*img_data; 
	int			img_size_l;
	int			img_bpp;
	int			img_width;
	int			img_height;

	char		*path_path;
	char		*path_wall;
	char		*path_player1;
	char		*path_exit;
	char		*path_collect;

	int			*x;
	int			*y;
}				t_mlx;

#endif