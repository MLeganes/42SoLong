#include "so_long.h"

void collectible_increase(t_mlx *mlx)
{
	mlx->map_collectibles++;
}

int collectible_check(t_mlx *mlx)
{
	if (mlx->map_collectibles == 0)
		return (0);
	return (mlx->map_collectibles); 
}
void collectible_decrease(t_mlx *mlx)
{
	mlx->map_collectibles--;
}