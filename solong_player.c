/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:44:03 by amorcill          #+#    #+#             */
/*   Updated: 2021/10/28 11:38:02 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//include <so_long.h>
#include "so_long.h"

int	player_move_a(t_mlx *mlx)
{
	mlx->player1_new_y = mlx->player1_vertical;
	mlx->player1_new_x = mlx->player1_horizontal - 1;
	mlx->player1_dir = PLAYER_DIR_A;
	player_update(mlx);	

	// new_y = mlx->player1_vertical;
	// new_x = (mlx->player1_horizontal) - 1;
	// if (mlx->map[new_y][new_x] == 'C')
	// {
	// }
	// if (mlx->map[new_y][new_x] == '0')
	// {
	// 	map_update_path(mlx, mlx->player1_horizontal, mlx->player1_vertical);
	// 	map_update_player(mlx, new_x, new_y);
	// }
	// if (mlx->map[new_y][new_x] == 'E')
	// {
	// 	exit_game();
	// }
	return (0);
}

int	player_move_s(t_mlx *mlx)
{	
	mlx->player1_new_y = mlx->player1_vertical + 1;
	mlx->player1_new_x = mlx->player1_horizontal;
	mlx->player1_dir = PLAYER_DIR_S;
	
	player_update(mlx);	
	// new_y = (mlx->player1_vertical) + 1;
	// new_x = mlx->player1_horizontal;
	// if (mlx->map[new_y][new_x] == 'C')
	// {
	// }
	// if (mlx->map[new_y][new_x] == '0')
	// {
	// 	map_update_path(mlx, mlx->player1_horizontal, mlx->player1_vertical);
	// 	map_update_player(mlx, new_x, new_y);
	// }
	// if (mlx->map[new_y][new_x] == 'E')
	// {
	// 	exit_game();
	// }
	return (0);
}

int	player_move_d(t_mlx *mlx)
{
	mlx->player1_new_y = mlx->player1_vertical;
	mlx->player1_new_x = (mlx->player1_horizontal) + 1;
	mlx->player1_dir = PLAYER_DIR_D;
	player_update(mlx);	
	// if (mlx->map[new_y][new_x] == 'C')
	// {
	// }
	// else if (mlx->map[new_y][new_x] == '0')
	// {
	// 	map_update_path(mlx, mlx->player1_horizontal, mlx->player1_vertical);
	// 	map_update_player(mlx, new_x, new_y);
	// }
	// else if (mlx->map[new_y][new_x] == 'E')
	// {
	// 	exit_game();
	// }
	return (0);
}

int	player_move_w(t_mlx *mlx)
{	
	mlx->player1_new_y = (mlx->player1_vertical) - 1;
	mlx->player1_new_x = mlx->player1_horizontal;
	mlx->player1_dir = PLAYER_DIR_W;
	player_update(mlx);	
	return (0);
}

void player_update(t_mlx *mlx)
{
	int		new_xy[2];

	new_xy[0] = mlx->player1_new_x;
	new_xy[1] = mlx->player1_new_y;	
	if (mlx->map[new_xy[1]][new_xy[0]] == '0' || mlx->map[new_xy[1]][new_xy[0]] == 'C')
	{
		if (mlx->map[new_xy[1]][new_xy[0]] == 'C')
		{
			collectible_decrease(mlx);
			map_update_path(mlx,new_xy[0], new_xy[1]);
		}
		map_update_path(mlx, mlx->player1_horizontal, mlx->player1_vertical);
		map_update_player(mlx, new_xy[0], new_xy[1]);
	}
	if (mlx->map[new_xy[1]][new_xy[0]] == 'E')
	{
		if (collectible_check(mlx) == 0)
			// No close the win and write zyou win.
			exit_game();
	}	
}