/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:15:52 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/12 18:29:11 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_load(t_mlx *mlx, int w, int h)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->imgs[IMG_EXIT].img, w * ZOOM, h * ZOOM);
}

int	exit_game(t_mlx *mlx)
{
	int	i;
	int	imgmax;

	i = 0;
	imgmax = IMG_MAX;
	if (mlx->bonus == 0)
		imgmax = IMG_MAX - 1;
	while (i < imgmax)
	{
		mlx_destroy_image(mlx->mlx, mlx->imgs[i].img);
		i++;
	}
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit (0);
}

void	game_win(t_mlx *mlx)
{
	int	x;
	int	y;

	x = (mlx->imap.width) / 2;
	y = (mlx->imap.height) / 2;
	map_load_path2(mlx, (x - 1), (y - 1));
	map_load_path2(mlx, (x), (y - 1));
	map_load_path2(mlx, (x + 1), (y - 1));
	map_load_path2(mlx, (x - 1), (y));
	map_load_path2(mlx, (x), (y));
	map_load_path2(mlx, (x + 1), (y));
	mlx_string_put(mlx->mlx, mlx->win, ((mlx->imap.width) / 2) * ZOOM,
		((mlx->imap.height) / 2) * ZOOM, 0x00FFFFFFF, ":) YOU WIN!!!");
}

void	game_over(t_mlx *mlx)
{
	int	x;
	int	y;

	x = (mlx->imap.width) / 2;
	y = (mlx->imap.height) / 2;
	map_load_path2(mlx, (x - 1), (y - 1));
	map_load_path2(mlx, (x), (y - 1));
	map_load_path2(mlx, (x + 1), (y - 1));
	map_load_path2(mlx, (x - 1), (y));
	map_load_path2(mlx, (x), (y));
	map_load_path2(mlx, (x + 1), (y));
	mlx_string_put(mlx->mlx, mlx->win, ((mlx->imap.width) / 2) * ZOOM,
		((mlx->imap.height) / 2) * ZOOM, 0x00FFFFFFF, ":| GAME OVER!!!");
}
