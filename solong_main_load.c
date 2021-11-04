/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_main_load.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:41:00 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/04 20:59:15 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	main_load_map(t_mlx *mlx, char **argv)
{
	int		lines;
	char	*line;
	int		fd;

	ft_count_lines(mlx, argv);
	lines = mlx->imap.height;
	mlx->map = (char **)malloc((lines + 1) * (sizeof(char *)));
	if (mlx->map == NULL)
		error_print_exit
		("[malloc error] Error to allocate memory with malloc!");
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		error_print_exit
		("[map error] Error to open map file! Check the path to the map.");
	line = get_next_line(fd);
	lines = 0;
	while (line)
	{
		ft_remove_eol(line);
		mlx->map[lines] = line;
		line = get_next_line(fd);
		lines++;
	}
	mlx->map[lines] = NULL;
}

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