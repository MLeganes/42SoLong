/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_map_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:17:18 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/12 18:08:11 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_check_wall(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '1')
			error_print_exit
				("[map error] Map no well formed. Invalid wall entry!");
		i++;
	}
	return ;
}

void	map_check_midline(t_mlx *mlx, char *s)
{
	int	i;

	if (s[0] != '1' || s[ft_strlen(s) - 1] != '1')
		error_print_exit("[map error] Map contains invalid wall entry!");
	i = 1;
	while (s[i] != '\0')
	{
		map_valic_characters(mlx, s, i);
		if (s[i] == 'P')
			mlx->imap.players++;
		if (s[i] == 'E')
			mlx->imap.exit++;
		if (s[i] == 'C')
			collectible_increase(mlx);
		i++;
	}
	return ;
}

static void	map_check_linelength(t_mlx *mlx)
{
	int		i;
	size_t	len;
	char	*line;
	size_t	auxlen;

	if (mlx->imap.width == mlx->imap.height)
		error_print_exit("[map error] Map is square, no valid!");
	i = 1;
	len = ft_strlen(mlx->map[0]);
	while (mlx->map[i] != NULL)
	{
		line = mlx->map[i];
		auxlen = ft_strlen(mlx->map[i]);
		if (len != auxlen)
			error_print_exit("[map error] Map contains differents lengths!");
		i++;
	}
	return ;
}

static void	map_check_minimum(t_mlx *mlx)
{
	if (mlx->imap.players < 1)
		error_print_exit("[map error] Map does not have player!");
	if (mlx->imap.exit < 1)
		error_print_exit("[map error] Map does not have exit!");
	if (mlx->imap.collectibles < 1)
		error_print_exit("[map error] Map does not have collectibles!");
	return ;
}

void	map_check(t_mlx *mlx)
{
	int		height;
	char	*line;

	map_check_linelength(mlx);
	height = 0;
	line = NULL;
	while (height < mlx->imap.height && mlx->map[height] != NULL)
	{
		line = mlx->map[height];
		if (height == 0 || height == mlx->imap.height - 1)
			map_check_wall(line);
		else
			map_check_midline(mlx, line);
		height++;
	}
	map_check_minimum(mlx);
	return ;
}
