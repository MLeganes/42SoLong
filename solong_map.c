/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:50:14 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/12 18:07:13 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_update_path(t_mlx *mlx, int x, int y)
{	
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PATH_2].img,
		x * ZOOM, y * ZOOM);
	mlx->map[y][x] = '0';
	return ;
}

void	map_update_player(t_mlx *mlx, int x, int y)
{
	if (mlx->player1.dir == PLAYER_DIR_A)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PLAY_A].img,
			x * ZOOM, y * ZOOM);
	if (mlx->player1.dir == PLAYER_DIR_S)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PLAY_S].img,
			x * ZOOM, y * ZOOM);
	if (mlx->player1.dir == PLAYER_DIR_W)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PLAY_W].img,
			x * ZOOM, y * ZOOM);
	if (mlx->player1.dir == PLAYER_DIR_D)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PLAY_D].img,
			x * ZOOM, y * ZOOM);
	mlx->map[y][x] = 'P';
	mlx->player1.horizontal = x;
	mlx->player1.vertical = y;
	return ;
}

void	map_valic_characters(t_mlx *mlx, char *s, int i)
{	
	if (mlx->bonus == 0)
	{
		if (s[i] != '1' && s[i] != '0' && s[i] != 'P'
			&& s[i] != 'E' && s[i] != 'C')
			error_print_exit("[map error] Map contains an invalid entry.");
	}
	if (mlx->bonus == 1)
	{
		if (s[i] != '1' && s[i] != '0' && s[i] != 'P'
			&& s[i] != 'E' && s[i] != 'C' && s[i] != 'G')
			error_print_exit("[map error] Map contains an invalid entry.");
	}
}
