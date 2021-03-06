/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_key_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:31:29 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/12 19:06:25 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_events(int key, t_mlx *mlx)
{
	if (mlx->player1.lives == 1 && mlx->player1.game_on == 1)
	{
		if (key == 0 || key == 123)
			player_move_a(mlx);
		if (key == 1 || key == 125)
			player_move_s(mlx);
		if (key == 2 || key == 124)
			player_move_d(mlx);
		if (key == 13 || key == 126)
			player_move_w(mlx);
	}
	if (mlx->bonus == 1)
		mlx_loop_hook(mlx->mlx, ghost_move, mlx);
	if (key == 53)
		exit_game(mlx);
	return (1);
}
