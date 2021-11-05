/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_map_load.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:15:12 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/05 13:49:04 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_load_path1(t_mlx *mlx, int w, int h)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->imgs[IMG_PATH_1].img, w * ZOOM, h * ZOOM);
}

void	map_load_path2(t_mlx *mlx, int w, int h)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->imgs[IMG_PATH_2].img, w * ZOOM, h * ZOOM);
}

void	map_load_wall(t_mlx *mlx, int w, int h)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->imgs[IMG_WALL].img, w * ZOOM, h * ZOOM);
}

void	map_load_init_player(t_mlx *mlx, int w, int h)
{
	if (mlx->player1.printed == 0)
	{		
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->imgs[IMG_PLAY_D].img, w * ZOOM, h * ZOOM);
		mlx->player1.printed = 1;
	}
	else
	{
		map_load_path1(mlx, w, h);
		mlx->map[h][w] = '0';
	}	
	mlx->player1.horizontal = w;
	mlx->player1.vertical = h;
}
