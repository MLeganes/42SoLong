/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:39:30 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/12 16:48:02 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ghost_move(t_mlx *mlx)
{
	int			i;
	int			ghosts;
	static int	timer;

	timer++;
	if (timer > 1000 && (mlx->player1.game_on == 1 || mlx->player1.lives > 1))
	{	
		ghosts = mlx->imap.ghost;
		i = 0;
		while (i < ghosts)
		{
			mlx->ghost_id = i;
			ft_move_ramdom(mlx);
			i++;
		}
		timer = 0;
	}
	return (0);
}

void	ft_move_ramdom(t_mlx *mlx)
{
	int	nb;
	int	i;

	nb = rand();
	i = mlx->ghost_id;
	if ((nb % 4) == 0)
	{
		if (ghost_check(mlx, mlx->ghost[i].x + 1, mlx->ghost[i].y))
			ghost_move_secondpart(mlx, mlx->ghost[i].x + 1, mlx->ghost[i].y);
	}
	if (nb % 4 == 1)
	{
		if (ghost_check(mlx, mlx->ghost[i].x, mlx->ghost[i].y - 1))
			ghost_move_secondpart(mlx, mlx->ghost[i].x, mlx->ghost[i].y - 1);
	}
	if (nb % 4 == 2)
	{
		if (ghost_check(mlx, mlx->ghost[i].x - 1, mlx->ghost[i].y))
			ghost_move_secondpart(mlx, mlx->ghost[i].x - 1, mlx->ghost[i].y);
	}
	if (nb % 4 == 3)
	{
		if (ghost_check(mlx, mlx->ghost[i].x, mlx->ghost[i].y + 1))
			ghost_move_secondpart(mlx, mlx->ghost[i].x, mlx->ghost[i].y + 1);
	}
}

int	ghost_check(t_mlx *mlx, int x, int y)
{
	if (x > 0 && x < mlx->imap.width && y > 0 && y < mlx->imap.height)
	{
		if (mlx->map[y][x] == '0' || mlx->map[y][x] == 'P')
			return (1);
	}
	return (0);
}

void	ghost_move_secondpart(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y][x] == '0')
	{		
		ghost_update(mlx, x, y);
		return ;
	}
	if (mlx->map[y][x] == 'P')
	{		
		ghost_player_crash(mlx, x, y);
		return ;
	}	
}

void	ghost_player_crash(t_mlx *mlx, int x, int y)
{
	map_load_path2(mlx, mlx->player1.horizontal, mlx->player1.vertical);
	map_load_path2(mlx, x, y);
	mlx->map[y][x] = '0';
	mlx->player1.lives = 0;
	mlx->player1.game_on = 0;
	score_print(mlx);
	game_over(mlx);
}
