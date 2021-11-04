/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:44:03 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/04 16:58:19 by amorcill         ###   ########.fr       */
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
	int		new_xy[2];

	new_xy[0] = mlx->player1.new_x;
	new_xy[1] = mlx->player1.new_y;
	if (mlx->map[new_xy[1]][new_xy[0]] == '0' ||
		mlx->map[new_xy[1]][new_xy[0]] == 'C')
	{
		if (mlx->map[new_xy[1]][new_xy[0]] == 'C')
		{
			collectible_decrease(mlx);
			map_update_path(mlx, new_xy[0], new_xy[1]);
		}
		map_update_path(mlx, mlx->player1.horizontal, mlx->player1.vertical);
		map_update_player(mlx, new_xy[0], new_xy[1]);
		score_steps(mlx);
	}
	if (mlx->bonus == 1 && mlx->map[new_xy[1]][new_xy[0]] == 'G')
	{
		ghost_player_crash(mlx, new_xy[0], new_xy[1]);
	// 	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PATH_2].img, mlx->player1.horizontal * ZOOM, mlx->player1.vertical * ZOOM);
	// 	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PATH_2].img, new_xy[0] * ZOOM, new_xy[1] * ZOOM);
	// 	mlx->map[new_xy[1]][new_xy[0]] = '0';
	// 	mlx->player1.lives = 0;
	// 	score_print(mlx);
	// 	mlx_string_put(mlx->mlx, mlx->win, (mlx->imap.height / 2) * ZOOM, (mlx->imap.width / 2) * ZOOM, 0x00FFFFFFF, "GAME OVER");
	}
	if (mlx->map[new_xy[1]][new_xy[0]] == 'E')
	{
		if (collectible_check(mlx) == 0)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PATH_2].img,
			mlx->player1.horizontal * ZOOM, mlx->player1.vertical * ZOOM);
			mlx->player1.game_on = 0;
			game_win(mlx);			
		}			
	}
	if (mlx->bonus == 1)
	{
		mlx_loop_hook( mlx->mlx, ghost_move, mlx);
		//ghost_move(mlx);		
	}
}
