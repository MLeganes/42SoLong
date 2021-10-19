#include "so_long.h"

void collectible_increase(t_mlx *mlx)
{
	mlx->collectibles++;
}

int collectible_check(t_mlx *mlx)
{
	if (mlx->collectibles == 0)
		return (0);
	return (1); 
}
void collectible_decrease(t_mlx *mlx)
{
	mlx->collectibles--;
}