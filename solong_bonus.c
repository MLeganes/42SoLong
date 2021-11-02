/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: x250 <x250@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 04:19:20 by x250              #+#    #+#             */
/*   Updated: 2021/10/30 04:22:57 by x250             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_load_ghost(t_mlx *mlx, int x, int y)
{
	int	ghost;

	ghost = mlx->imap.ghost;
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->imgs[IMG_PINK].img, x * ZOOM, y * ZOOM);
	mlx->ghost[ghost].horizontal = x;
	mlx->ghost[ghost].vertical = y;
	mlx->imap.ghost++;
}

void	ghost_move(t_mlx *mlx)
{
	int	i;
	int	ghosts;

	ghosts = mlx->imap.ghost;
	i = 0;
	while (i < ghosts)
	{
		if (mlx->map[mlx->ghost[i].y][mlx->ghost[i].x + 1] == '0' ||
			mlx->map[mlx->ghost[i].y][mlx->ghost[i].x + 1] == 'P')
			ghost_move_secondpart(mlx, mlx->ghost[i].x + 1, mlx->ghost[i].y);
		else if (mlx->map[mlx->ghost[i].y + 1][mlx->ghost[i].x] == '0' ||
				 mlx->map[mlx->ghost[i].y + 1][mlx->ghost[i].x] == 'P')
			ghost_move_secondpart(mlx, mlx->ghost[i].x, mlx->ghost[i].y + 1);
		else if (mlx->map[mlx->ghost[i].y][mlx->ghost[i].x - 1] == '0' ||
				 mlx->map[mlx->ghost[i].y][mlx->ghost[i].x - 1] == 'P')
			ghost_move_secondpart(mlx, mlx->ghost[i].x - 1, mlx->ghost[i].y);
		else if (mlx->map[mlx->ghost[i].y - 1][mlx->ghost[i].x] == '0' ||
				 mlx->map[mlx->ghost[i].y - 1][mlx->ghost[i].x] == 'P')
			ghost_move_secondpart(mlx, mlx->ghost[i].x, mlx->ghost[i].y + 1);
		i++;
	}
}

void	ghost_move_secondpart(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y][x] == 'P')
		ghost_player_crash(mlx, x, y);
	ghost_update(mlx->ghost[i], x, y);
}

void	ghost_update(t_ghost *ghost, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->imgs[IMG_PINK].img, x * ZOOM, y * ZOOM);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->imgs[IMG_PATH_2].img, ghost->x * ZOOM, ghost->y * ZOOM);
	mlx->map[mlx->ghost[i].y][mlx->ghost[i].x] = 0;
	mlx->map[y][x] = 'G';
	ghost->x = x;
	ghost->y = y;
}

void	ghost_player_crash(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PATH_2].img,
		mlx->player1.horizontal * ZOOM, mlx->player1.vertical * ZOOM);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PATH_2].img,
		x * ZOOM, y * ZOOM);
	mlx->map[y][x] = '0';
	mlx->player1.lives = 0;
	score_print(mlx);
	mlx_string_put(mlx->mlx, mlx->win, (mlx->imap.height / 2) * ZOOM,
		(mlx->imap.width / 2) * ZOOM, 0x00FFFFFFF, "GAME OVER");
}
