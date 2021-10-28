/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:44:03 by amorcill          #+#    #+#             */
/*   Updated: 2021/10/28 19:22:16 by amorcill         ###   ########.fr       */
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

void player_update(t_mlx *mlx)
{
	int		new_xy[2];

	new_xy[0] = mlx->player1.new_x;
	new_xy[1] = mlx->player1.new_y;	
	if (mlx->map[new_xy[1]][new_xy[0]] == '0' || mlx->map[new_xy[1]][new_xy[0]] == 'C')
	{
		if (mlx->map[new_xy[1]][new_xy[0]] == 'C')
		{
			collectible_decrease(mlx);
			map_update_path(mlx,new_xy[0], new_xy[1]);
		}
		map_update_path(mlx, mlx->player1.horizontal, mlx->player1.vertical);
		map_update_player(mlx, new_xy[0], new_xy[1]);
	}
	if (mlx->map[new_xy[1]][new_xy[0]] == 'E')
	{
		if (collectible_check(mlx) == 0)
			// No close the win and write zyou win.
			exit_game();
	}
	score_steps(mlx);
}