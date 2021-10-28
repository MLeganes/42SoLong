//#include <so_long.h>
#include "so_long.h"

void map_update_path(t_mlx *mlx, int x, int y)
{	
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PATH_2].img, x * ZOOM, y * ZOOM);
	mlx->map[y][x] = '0';
	return ;
}

void map_update_player(t_mlx *mlx, int x, int y)
{

	if(mlx->player1.dir == PLAYER_DIR_A)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PLAY_A].img, x * ZOOM, y * ZOOM);		
	if(mlx->player1.dir == PLAYER_DIR_S)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PLAY_S].img, x * ZOOM, y * ZOOM);	
	if(mlx->player1.dir == PLAYER_DIR_W)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PLAY_W].img, x * ZOOM, y * ZOOM);
	if(mlx->player1.dir == PLAYER_DIR_D)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PLAY_D].img, x * ZOOM, y * ZOOM);	
	mlx->map[y][x] = 'P';
	mlx->player1.horizontal = x;
	mlx->player1.vertical = y;
	return ;
}

static void map_check_wall(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if ( s[i] != '1')
			error_print_exit("[map error] Map no well formed. Invalid wall entry!");		
		i++;
	}
	return ;
}

void	map_check_midline(t_mlx *mlx, char *s)
{
	int i;
	int len;

	len = strlen(s);
	if (s[0] != '1' || s[len - 1] != '1')
		error_print_exit("[map error] Map contains invalid wall entry!");
	i = 1;
	while (s[i] != '\0')
	{
		if ( s[i] != '1' && s[i] != '0' && s[i] != 'P' && s[i] != 'E' && s[i] != 'C')
			error_print_exit("[map error] Map contains an invalid entry. It must contain 0, 1, C, E and P.");
		else
		{		
			if (s[i] == 'P')
				mlx->imap.players++;
			if (s[i] == 'E')
				mlx->imap.exit++;
			if (s[i] == 'C')
				collectible_increase(mlx);			
		}
		i++;
	}
	return ;
}

static void map_check_linelength(t_mlx *mlx)
{
	int		i;
	size_t	len;
	char 	*line;
	size_t	auxlen;
	
	if (mlx->imap.width == mlx->imap.height)
		error_print_exit("[map error] Map is square, no valid!");
	i = 1;
	len = ft_strlen(mlx->map[0]);
	while (mlx->map[i] != NULL)
	{
		line = mlx->map[i];
		auxlen = ft_strlen(mlx->map[i]);
		if (len != auxlen )
			error_print_exit("[map error] Map contains differents line lengths entry!");
		i++;	
	}
	return ;
}
static void map_check_minimum(t_mlx *mlx)
{
	if (mlx->imap.players < 1)
		error_print_exit("[map error] Map does not have player!");
	if (mlx->imap.exit < 1)
		error_print_exit("[map error] Map does not have exit!");
	if (mlx->imap.collectibles < 1)
		error_print_exit("[map error] Map does not have collectibles!");
	return ;
}

void map_check(t_mlx *mlx)
{
	int		height;
	char	*line;
	
	map_check_linelength(mlx);		
	height = 0;
	line = NULL;
	while(height < mlx->imap.height &&  mlx->map[height] != NULL)
	{
		line = mlx->map[height];
		if( height == 0 || height == mlx->imap.height - 1)
			map_check_wall(line);
		else
			map_check_midline(mlx, line);
		height++;
	}
	map_check_minimum(mlx);
	return ;
}
