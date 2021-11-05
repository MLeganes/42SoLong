/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_load_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:46:06 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/05 15:57:05 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_image_ghost(t_mlx *mlx)
{
	mlx->imgs[IMG_PINK].img = mlx_xpm_file_to_image(mlx->mlx,
			"./imgs/red.xpm", &mlx->imgs[IMG_PINK].width,
			&mlx->imgs[IMG_PINK].height);
}
