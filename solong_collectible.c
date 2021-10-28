#include "so_long.h"

void collectible_increase(t_mlx *mlx)
{
	mlx->imap.collectibles++;
}

int collectible_check(t_mlx *mlx)
{
	if (mlx->imap.collectibles == 0)
		return (0);
	return (mlx->imap.collectibles); 
}
void collectible_decrease(t_mlx *mlx)
{
	mlx->imap.collectibles--;
}