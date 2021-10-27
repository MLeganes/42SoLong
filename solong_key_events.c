/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_key_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:31:29 by amorcill          #+#    #+#             */
/*   Updated: 2021/10/27 15:04:34 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <so_long.h>
#include "so_long.h"

int key_events(int key, t_mlx *mlx)
{	
	if(key == 0 || key == 123)
	{
		player_move_a(mlx);
	}
	if(key == 1 || key == 125)
	{
		player_move_s(mlx);		
	}
	if(key == 2 || key == 124)
	{
		player_move_d(mlx);				
	}	
	if(key == 13 || key == 126)
	{
		player_move_w(mlx);
	}	
	if(key == 53)
	{		
		exit_game ();
	}
	return (1);
}