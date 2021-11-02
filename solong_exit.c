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
