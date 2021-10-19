//#include <so_long.h>
#include "so_long.h"

void map_update_path(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pointer_path,	x * 100, y * 100);
	mlx->map[y][x] = '0';	
}

void map_update_player(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pointer_player1, x * 100, y * 100);
	mlx->map[y][x] = 'P';
	mlx->player1_horizontal = x;
	mlx->player1_vertical = y;
}

int map_check_ones(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n' || s[i] != '\0')
	{
		if ( s[i] != '1')
			return (-1);
	}
	return (1);
}

int map_check_otherlines(char *s)
{
	int i;
	int len;

	len = strlen(s);

	i = 0;
	while (s[i] != '\n' || s[i] != '\0')
	{
		if (s[0] != '1' || s[len] != '1')
			retun (-1);
		else
		{
			if (s[i] == '0')
				continue;
			if (s[i] == 'P')
				//count player ++
			if (s[i] == 'E')
				//counter exit ++
			if (s[i] == 'C')
				// count collecti ++
		}
	}
	return (1);
}

int map_check(t_mlx *mlx)
{
	int		height;
	char	*line;
	
	if (mlx->img_width == mlx->img_height)
		return (0);
	height = 0;
	line = NULL;
	while(height < mlx->img_height)
	{
		line = mlx->map[height];			
		if( height == 0 || height == mlx->img_height)
		{
			if (map_check_wall(line))
				return (-1);			
		}
		else{
			if (map_check_midline(line))
				return (-1);
		}		
		height++;
	}
	return (1);
}






	   /*
		*
		*
		
			aux = mlx->map[height][width];
			if(mlx->map[height][w] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pointer_path,	width* 100, height * 100);
			if(mlx->map[height][w] == '1' )
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pointer_wall,	width* 100, height * 100);
			if(mlx->map[height][w] == 'P' )
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pointer_player1,	width* 100, height * 100);
				mlx->player1_horizontal = w;
				mlx->player1_vertical = height;				
			}
			if(mlx->map[height][w] == 'C' )
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pointer_collect,	width* 100, height * 100);
				collectible_increase(mlx);
				
			}
			if(mlx->map[height][w] == 'E' )
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pointer_exit,	width* 100, height * 100);
			width++;
		}
		height++;

		***/
