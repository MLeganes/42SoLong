#include "so_long.h"

int	exit_game(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < IMG_MAX)
	{
		mlx_destroy_image(mlx->mlx, mlx->imgs[i].img);
		i++;
	}
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit (0);
}

void game_win(t_mlx *mlx)
{
	int x;
	int y;

	x = (mlx->imap.width) / 2;
	y = (mlx->imap.height) / 2;
	
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PATH_2].img, (x - 1) * ZOOM, (y - 1) * ZOOM);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PATH_2].img, (x) * ZOOM, (y - 1) * ZOOM);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PATH_2].img, (x + 1) * ZOOM, (y - 1) * ZOOM);
	
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PATH_2].img, (x - 1) * ZOOM, (y) * ZOOM);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PATH_2].img, (x) * ZOOM, (y) * ZOOM);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PATH_2].img, (x + 1) * ZOOM, (y) * ZOOM);
	
	mlx_string_put(mlx->mlx, mlx->win, ((mlx->imap.width) / 2) * ZOOM,
		((mlx->imap.height) / 2) * ZOOM, 0x00FFFFFFF, "YOU WIN!!!!!!");
}
