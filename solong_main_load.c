/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_main_load.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:41:00 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/04 20:44:11 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void main_load_image_map(t_mlx *mlx)
{
	mlx->imgs[IMG_PATH_1].img = mlx_xpm_file_to_image
		(mlx->mlx, "./imagens/path.xpm", &mlx->imgs[IMG_PATH_1].width,
			&mlx->imgs[IMG_PATH_1].height);
	mlx->imgs[IMG_PATH_2].img = mlx_xpm_file_to_image
		(mlx->mlx, "./imagens/back.xpm", &mlx->imgs[IMG_PATH_2].width,
			&mlx->imgs[IMG_PATH_2].height);
	mlx->imgs[IMG_WALL].img = mlx_xpm_file_to_image(mlx->mlx,
			"./imagens/wall.xpm", &mlx->imgs[IMG_WALL].width,
			&mlx->imgs[IMG_WALL].height);
	mlx->imgs[IMG_EXIT].img = mlx_xpm_file_to_image(mlx->mlx,
			"./imagens/exit.xpm", &mlx->imgs[IMG_EXIT].width,
			&mlx->imgs[IMG_EXIT].height);
	mlx->imgs[IMG_COLLECT].img = mlx_xpm_file_to_image(mlx->mlx,
			"./imagens/button.xpm", &mlx->imgs[IMG_COLLECT].width,
			&mlx->imgs[IMG_COLLECT].height);
}

void main_load_image_player(t_mlx *mlx)
{
	mlx->imgs[IMG_PLAY_S].img = mlx_xpm_file_to_image(mlx->mlx,
			"./imagens/pacmanDown.xpm", &mlx->imgs[IMG_PLAY_S].width,
			&mlx->imgs[IMG_PLAY_S].height);
	mlx->imgs[IMG_PLAY_A].img = mlx_xpm_file_to_image(mlx->mlx,
			"./imagens/pacmanLeft.xpm", &mlx->imgs[IMG_PLAY_A].width,
			&mlx->imgs[IMG_PLAY_A].height);
	mlx->imgs[IMG_PLAY_W].img = mlx_xpm_file_to_image(mlx->mlx,
			"./imagens/pacmanUp.xpm", &mlx->imgs[IMG_PLAY_W].width,
			&mlx->imgs[IMG_PLAY_W].height);
	mlx->imgs[IMG_PLAY_D].img = mlx_xpm_file_to_image(mlx->mlx,
			"./imagens/pacmanRight.xpm", &mlx->imgs[IMG_PLAY_D].width,
			&mlx->imgs[IMG_PLAY_D].height);
}