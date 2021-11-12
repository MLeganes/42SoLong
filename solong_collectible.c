/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_collectible.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:35:58 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/12 16:36:00 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectible_increase(t_mlx *mlx)
{
	mlx->imap.collectibles++;
}

int	collectible_check(t_mlx *mlx)
{
	if (mlx->imap.collectibles == 0)
		return (0);
	return (mlx->imap.collectibles);
}

void	collectible_decrease(t_mlx *mlx)
{
	mlx->imap.collectibles--;
	score_collectibles(mlx);
}

void	collectible_load(t_mlx *mlx, int w, int h)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->imgs[IMG_COLLECT].img, w * ZOOM, h * ZOOM);
}
