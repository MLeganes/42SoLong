#include "so_long.h"

void	collectible_increase(t_mlx *mlx)
{
	mlx->imap.collectibles++;
}

int	collectible_check(t_mlx *mlx)
{
	if (mlx->imap.collectibles == 0)
		return (0);
	return (mlx->imap.collectibles);
}

void	collectible_decrease(t_mlx *mlx)
{
	mlx->imap.collectibles--;
	score_collectibles(mlx);
}
void	collectible_load(t_mlx *mlx, int w, int h)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->imgs[IMG_COLLECT].img, w * ZOOM, h * ZOOM);
}