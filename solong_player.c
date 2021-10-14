/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:44:03 by amorcill          #+#    #+#             */
/*   Updated: 2021/10/14 17:22:06 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//include <so_long.h>
#include "so_long.h"

int player_move_a(t_mlx *mlx)
{
	printf("Move A heig: %d wid:%d  ", mlx->img_height, mlx->img_width);
	return (0);
}
int player_move_s(t_mlx *mlx)
{
	printf("Move S heig: %d wid:%d  ", mlx->img_height, mlx->img_width);
	return (0);
}
int player_move_d(t_mlx *mlx)
{
	printf("Move D heig: %d wid:%d  ", mlx->img_height, mlx->img_width);
	return (0);
}
int player_move_w(t_mlx *mlx)
{
	int hor;	
	int ver;	
		
	hor = mlx->player1_horizontal;	
	ver = mlx->player1_vertical;	
	
	printf("Move W heig: %d wid:%d  ", mlx->img_height, mlx->img_width);
	if (mlx->map[ver - 1 ][hor] == 'C')
	{
		//	collect
		
	}
	if (mlx->map[ver - 1][hor] == '0')
	{
		//next is path, do something
		//mlx->player1_vertical--;
		// update player position in map
			// vertical -- with
			// hori     -- hei
					
		mlx->map[hor][ver] = '0';
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pointer_path,	ver * 100, hor * 100);		
		mlx->map[hor][ver - 1] = 'P';
		// update player position
		mlx->player1_horizontal = hor;
		mlx->player1_vertical = ver -1;		
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pointer_player1, (ver-1) * 100, hor * 100);	
			
	}
	if (mlx->map[ver - 1][hor] == 'E')
	{
		//Exit, do something
	}
	return (0);
}