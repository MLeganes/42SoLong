/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:44:03 by amorcill          #+#    #+#             */
/*   Updated: 2021/10/19 11:26:54 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//include <so_long.h>
#include "so_long.h"

int	player_move_a(t_mlx *mlx)
{
	int	new_x;
	int	new_y;

	new_y = mlx->player1_vertical;
	new_x = (mlx->player1_horizontal) - 1;
	if (mlx->map[new_y][new_x] == 'C')
	{
	}
	if (mlx->map[new_y][new_x] == '0')
	{
		map_update_path(mlx, mlx->player1_horizontal, mlx->player1_vertical);
		map_update_player(mlx, new_x, new_y);
	}
	if (mlx->map[new_y][new_x] == 'E')
	{
		exit_game();
	}
	return (0);
}

int	player_move_s(t_mlx *mlx)
{	
	int	new_x;
	int	new_y;

	new_y = (mlx->player1_vertical) + 1;
	new_x = mlx->player1_horizontal;
	if (mlx->map[new_y][new_x] == 'C')
	{
	}
	if (mlx->map[new_y][new_x] == '0')
	{
		map_update_path(mlx, mlx->player1_horizontal, mlx->player1_vertical);
		map_update_player(mlx, new_x, new_y);
	}
	if (mlx->map[new_y][new_x] == 'E')
	{
		exit_game();
	}
	return (0);
}

int	player_move_d(t_mlx *mlx)
{
	int	new_x;	
	int	new_y;	

	new_y = mlx->player1_vertical;
	new_x = (mlx->player1_horizontal) + 1;
	if (mlx->map[new_y][new_x] == 'C')
	{
	}
	else if (mlx->map[new_y][new_x] == '0')
	{
		map_update_path(mlx, mlx->player1_horizontal, mlx->player1_vertical);
		map_update_player(mlx, new_x, new_y);
	}
	else if (mlx->map[new_y][new_x] == 'E')
	{
		exit_game();
	}
	return (0);
}

int	player_move_w(t_mlx *mlx)
{
	int	new_x;
	int	new_y;

	new_y = (mlx->player1_vertical) - 1;
	new_x = mlx->player1_horizontal;
	if (mlx->map[new_y][new_x] == 'C')
	{
	}
	if (mlx->map[new_y][new_x] == '0')
	{
		map_update_path(mlx, mlx->player1_horizontal, mlx->player1_vertical);
		map_update_player(mlx, new_x, new_y);
	}
	if (mlx->map[new_y][new_x] == 'E')
	{
		exit_game();
	}
	return (0);
}
