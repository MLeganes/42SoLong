/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_load_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:46:06 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/12 18:24:04 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_load_ghost(t_mlx *mlx, int x, int y)
{
	int	ghost;

	ghost = mlx->imap.ghost;
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->imgs[IMG_PINK].img, x * ZOOM, y * ZOOM);
	mlx->ghost[ghost].x = x;
	mlx->ghost[ghost].y = y;
	mlx->imap.ghost++;
}

void	load_image_ghost(t_mlx *mlx)
{
	mlx->imgs[IMG_PINK].img = mlx_xpm_file_to_image(mlx->mlx,
			"./imgs/red.xpm", &mlx->imgs[IMG_PINK].width,
			&mlx->imgs[IMG_PINK].height);
}

void	ghost_update(t_mlx *mlx, int x, int y)
{
	int	id;

	id = mlx->ghost_id;
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->imgs[IMG_PINK].img, x * ZOOM, y * ZOOM);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->imgs[IMG_PATH_1].img,
		mlx->ghost[id].x * ZOOM,
		mlx->ghost[id].y * ZOOM);
	mlx->map[mlx->ghost[id].y][mlx->ghost[id].x] = '0';
	mlx->map[y][x] = 'G';
	mlx->ghost[id].x = x;
	mlx->ghost[id].y = y;
}
