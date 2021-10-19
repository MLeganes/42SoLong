//#include <so_long.h>
#include "so_long.h"

void map_update_position(t_mlx *mlx, int x, int y)
{
	int ver;
	int hor;

	ver = mlx->player1_vertical;
	hor = mlx->player1_horizontal;
	printf("Hola %d %d", x, y);	
}

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