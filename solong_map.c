//#include <so_long.h>
#include "so_long.h"

void map_update_path(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pointer_path,	x * ZOOM, y * ZOOM);
	mlx->map[y][x] = '0';	
}

void map_update_player(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pointer_player1, x * ZOOM, y * ZOOM);
	mlx->map[y][x] = 'P';
	mlx->player1_horizontal = x;
	mlx->player1_vertical = y;
}

static void map_check_wall(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if ( s[i] != '1')
			error_print_exit("[map error] Map no well formed. Problems with the walls!!!");		
		i++;
	}
}

void	map_check_midline(t_mlx *mlx, char *s)
{
	int i;
	int len;

	len = strlen(s);
	if (s[0] != '1' || s[len - 1] != '1')
		error_print_exit("[map error] Map containt invalid entry. Problems with the walls!!!");
	i = 1;
	while (s[i] != '\0')
	{
		if ( s[i] != '1' && s[i] != '0' && s[i] != 'P' && s[i] != 'E' && s[i] != 'C')
			error_print_exit("[map error] Map containt invalid entry!!!");
		else
		{		
			if (s[i] == 'P')
				mlx->map_players++;
			if (s[i] == 'E')
				mlx->map_exit++;
			if (s[i] == 'C')
				collectible_increase(mlx);			
		}
		i++;
	}
}

static void map_check_linelength(t_mlx *mlx)
{
	int		i;
	size_t	len;
	char 	*line;
	size_t	auxlen;
	
	if (mlx->img_width == mlx->img_height)
		error_print_exit("[map error] Map is square, no valid!!!");
	i = 1;
	len = ft_strlen(mlx->map[0]);
	while (mlx->map[i] != NULL)
	{
		line = mlx->map[i];
		auxlen = ft_strlen(mlx->map[i]);
		if (len != auxlen )
			error_print_exit("[map error] Map containt invalid entry!!!");
		i++;	
	}	
}

void map_check(t_mlx *mlx)
{
	int		height;
	char	*line;
	
	map_check_linelength(mlx);		
	height = 0;
	line = NULL;
	while(height < mlx->img_height &&  mlx->map[height] != NULL)
	{
		line = mlx->map[height];
		if( height == 0 || height == mlx->img_height - 1)
			map_check_wall(line);
		else
			map_check_midline(mlx, line);
		height++;
	}
}
