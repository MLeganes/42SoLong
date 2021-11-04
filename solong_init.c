/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:41:54 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/04 12:36:11 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_imap(t_mlx *mlx)
{
	mlx->imap.players = 0;
	mlx->imap.collectibles = 0;
	mlx->imap.ghost = 0;
	mlx->imap.exit = 0;
	mlx->imap.height = 0;
	mlx->imap.width = 0;
}

static void	init_player(t_mlx *mlx)
{
	mlx->player1.horizontal = 0;
	mlx->player1.printed = 0;
	mlx->player1.new_x = 0;
	mlx->player1.vertical = 0;
	mlx->player1.new_y = 0;
	mlx->player1.steps = 0;
	mlx->player1.collects = 0;
	mlx->player1.lives = 1;
	mlx->player1.game_on = 1;
}

void	main_init_mlx(t_mlx *mlx)
{
	mlx->name = " So Pacman ";
	init_imap(mlx);
	init_player(mlx);
}
