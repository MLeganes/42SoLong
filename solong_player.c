/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:44:03 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/12 19:06:16 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move_a(t_mlx *mlx)
{
	mlx->player1.new_y = mlx->player1.vertical;
	mlx->player1.new_x = mlx->player1.horizontal - 1;
	mlx->player1.dir = PLAYER_DIR_A;
	player_update(mlx);
}

void	player_move_s(t_mlx *mlx)
{	
	mlx->player1.new_y = mlx->player1.vertical + 1;
	mlx->player1.new_x = mlx->player1.horizontal;
	mlx->player1.dir = PLAYER_DIR_S;
	player_update(mlx);
}

void	player_move_d(t_mlx *mlx)
{
	mlx->player1.new_y = mlx->player1.vertical;
	mlx->player1.new_x = (mlx->player1.horizontal) + 1;
	mlx->player1.dir = PLAYER_DIR_D;
	player_update(mlx);
}

void	player_move_w(t_mlx *mlx)
{	
	mlx->player1.new_y = (mlx->player1.vertical) - 1;
	mlx->player1.new_x = mlx->player1.horizontal;
	mlx->player1.dir = PLAYER_DIR_W;
	player_update(mlx);
}

void	player_update(t_mlx *mlx)
{
	if (mlx->map[mlx->player1.new_y][mlx->player1.new_x] == '0' ||
		mlx->map[mlx->player1.new_y][mlx->player1.new_x] == 'C')
	{
		if (mlx->map[mlx->player1.new_y][mlx->player1.new_x] == 'C')
		{
			collectible_decrease(mlx);
			map_update_path(mlx, mlx->player1.new_x, mlx->player1.new_y);
		}
		map_update_path(mlx, mlx->player1.horizontal, mlx->player1.vertical);
		map_update_player(mlx, mlx->player1.new_x, mlx->player1.new_y);
		score_steps(mlx);
	}
	if (mlx->bonus == 1
		&& mlx->map[mlx->player1.new_y][mlx->player1.new_x] == 'G')
		ghost_player_crash(mlx, mlx->player1.new_x, mlx->player1.new_y);
	if (mlx->map[mlx->player1.new_y][mlx->player1.new_x] == 'E')
	{
		if (collectible_check(mlx) == 0)
		{
			map_load_path2(mlx, mlx->player1.horizontal, mlx->player1.vertical);
			mlx->player1.game_on = 0;
			game_win(mlx);
		}
	}	
}
