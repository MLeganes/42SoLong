/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:41:54 by amorcill          #+#    #+#             */
/*   Updated: 2021/10/28 18:07:55 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void main_init_mlx(t_mlx *mlx)
{
	mlx->name = " So Long ";
	mlx->map_players = 0;
	mlx->map_collectibles = 0;
	mlx->map_exit = 0;
	mlx->map_height = 0;
	mlx->map_width = 0;
	mlx->player1.horizontal = 0;
	mlx->player1.printed = 0;
	mlx->player1.new_x = 0;
	mlx->player1.vertical = 0;
	mlx->player1.new_y = 0;
}