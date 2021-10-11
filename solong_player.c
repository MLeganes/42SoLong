/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:44:03 by amorcill          #+#    #+#             */
/*   Updated: 2021/10/11 19:08:05 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int player_move_a(t_mlx *mlx)
{
	
}
int player_move_s(t_mlx *mlx)
{
	
}
int player_move_d(t_mlx *mlx)
{
	
}
int player_move_w(t_mlx *mlx)
{
	int hor;
	int ver;
	
	hor = mlx->player1_horizontal;
	ver = mlx->player1_vertical;
	
	if (mlx->map[ver - 1][hor] == 'C')
	{
		//	collect
		
	}
	if (mlx->map[ver - 1][hor] == '0')
	{
		//next is path, do something
		mlx->player1_vertical--;
		map_update_position(mlx, hor, ver);
		
	}
	if (mlx->map[ver - 1][hor] == 'E')
	{
		//Exit, do something
	}
	
}