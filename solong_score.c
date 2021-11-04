/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_score.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:38:15 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/04 12:48:27 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	score_print(t_mlx *mlx)
{
	char	*steps;
	char	*score;
	char	*lives;

	steps = ft_itoa(mlx->player1.steps);
	score = ft_itoa(mlx->player1.collects);
	lives = ft_itoa(mlx->player1.lives);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_WALL].img, 0 * ZOOM, 0 * ZOOM);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_WALL].img, 1 * ZOOM, 0 * ZOOM);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_WALL].img, 2 * ZOOM, 0 * ZOOM);
	mlx_string_put(mlx->mlx, mlx->win, 15, 20, 0x00FFFFFFF, "SCORE ");
	mlx_string_put(mlx->mlx, mlx->win, 15, 40, 0x00FFFFFFF, score);
	mlx_string_put(mlx->mlx, mlx->win, 80, 20, 0x00FFFFFFF, "STEPS ");
	mlx_string_put(mlx->mlx, mlx->win, 80, 40, 0x00FFFFFFF, steps);
	mlx_string_put(mlx->mlx, mlx->win, 140, 20, 0x00FFFFFFF, "LIVES ");
	mlx_string_put(mlx->mlx, mlx->win, 140, 40, 0x00FFFFFFF, lives);
}

void	score_steps(t_mlx *mlx)
{
	mlx->player1.steps++;
	//write(1, "Steps: ", 7);
	ft_putnbr_fd(mlx->player1.steps, 1);
	//write(1, "\n", 1);
	score_print(mlx);
}

void	score_collectibles(t_mlx *mlx)
{
	mlx->player1.collects++;
	//write(1, "Score: ", 7);
	ft_putnbr_fd(mlx->player1.collects, 1);
	//write(1, "\n", 1);
	score_print(mlx);
}
