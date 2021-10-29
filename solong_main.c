/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: x250 <x250@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:37:26 by amorcill          #+#    #+#             */
/*   Updated: 2021/10/29 11:02:23 by x250             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	main_check_args(int args, char **argv)
{
	int		error;
	char	*ret;
	char	aux[255];
	int		i;

	error = -1;
	if (args == 2)
	{
		ret = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
		i = 0;
		while (argv[1][i])
		{
			aux[i] = argv[1][i];
			i++;
		}
		if (ret != NULL && ret[4] == '\0')
		{
			error = 2;
		}
	}
	return (error);
}

/*
 * Load the map.ber. Read the file and save the lines.
 */

static int	main_load_map(t_mlx *mlx, char **argv)
{
	int		lines;
	char	*line;
	int		fd;

	ft_count_lines(mlx, argv);
	lines = mlx->imap.height;
	mlx->map = (char **)malloc((lines + 1) * (sizeof(char *)));
	if (mlx->map == NULL)
		return (-8);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (-2); // Call func. -2 error in open file
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
	if (close(fd) < 0)
		return (-4);
	return (1);
}

static void	main_init_load_xpmfile(t_mlx *mlx)
{	
	mlx->imgs[IMG_PATH_1].img = mlx_xpm_file_to_image(mlx->mlx, "./imagens/path.xpm", &mlx->imgs[IMG_PATH_1].width, &mlx->imgs[IMG_PATH_1].height );
	mlx->imgs[IMG_PATH_2].img = mlx_xpm_file_to_image(mlx->mlx, "./imagens/back.xpm", &mlx->imgs[IMG_PATH_2].width, &mlx->imgs[IMG_PATH_2].height );
	mlx->imgs[IMG_WALL].img = mlx_xpm_file_to_image(mlx->mlx, "./imagens/wall.xpm", &mlx->imgs[IMG_WALL].width, &mlx->imgs[IMG_WALL].height );
	mlx->imgs[IMG_EXIT].img = mlx_xpm_file_to_image(mlx->mlx, "./imagens/exit.xpm", &mlx->imgs[IMG_EXIT].width, &mlx->imgs[IMG_EXIT].height );
	mlx->imgs[IMG_COLLECT].img = mlx_xpm_file_to_image(mlx->mlx, "./imagens/button.xpm", &mlx->imgs[IMG_COLLECT].width, &mlx->imgs[IMG_COLLECT].height );
	mlx->imgs[IMG_PLAY_S].img = mlx_xpm_file_to_image(mlx->mlx, "./imagens/pacmanDown.xpm", &mlx->imgs[IMG_PLAY_S].width, &mlx->imgs[IMG_PLAY_S].height );
	mlx->imgs[IMG_PLAY_A].img = mlx_xpm_file_to_image(mlx->mlx, "./imagens/pacmanLeft.xpm", &mlx->imgs[IMG_PLAY_A].width, &mlx->imgs[IMG_PLAY_A].height );
	mlx->imgs[IMG_PLAY_W].img = mlx_xpm_file_to_image(mlx->mlx, "./imagens/pacmanUp.xpm", &mlx->imgs[IMG_PLAY_W].width, &mlx->imgs[IMG_PLAY_W].height );
	mlx->imgs[IMG_PLAY_D].img = mlx_xpm_file_to_image(mlx->mlx, "./imagens/pacmanRight.xpm", &mlx->imgs[IMG_PLAY_D].width, &mlx->imgs[IMG_PLAY_D].height );	
}

static int	main_init_load_image_base(t_mlx *mlx)
{
	int		height;
	int		w;
	char	aux;

	height = 0;
	w = 0;
	while (height < mlx->imap.height)
	{
		w = 0;
		while (w < mlx->imap.width)
		{
			aux = mlx->map[height][w];
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PATH_1].img, w * ZOOM, height * ZOOM);
			w++;
		}
		height++;
	}
	return (0);
}

static void main_init_load_image(t_mlx *mlx)
{
	int		height;
	int		w;
	char	aux;

	main_init_load_image_base(mlx);
	height = 0;
	while (height < mlx->imap.height)
	{
		w = 0;
		while (w < mlx->imap.width)
		{
			aux = mlx->map[height][w];
			if (mlx->map[height][w] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PATH_1].img, w * ZOOM, height * ZOOM);
			if (mlx->map[height][w] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_WALL].img, w * ZOOM, height * ZOOM);
			if (mlx->map[height][w] == 'P')
			{
				if (mlx->player1.printed == 0)
				{
					mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PLAY_D].img,  w * ZOOM, height * ZOOM);											
					mlx->player1.horizontal = w;
					mlx->player1.vertical = height;
					mlx->player1.printed = 1;
				}
				else
				{
					mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PATH_1].img, w * ZOOM, height * ZOOM);
					mlx->map[height][w] = '0';					
				}
			}
			if (mlx->map[height][w] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_COLLECT].img, w * ZOOM, height * ZOOM);
			if (mlx->map[height][w] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_EXIT].img, w * ZOOM, height * ZOOM);
			w++;
		}
		height++;
	}
}

int	main(int argc, char **argv)
{
	//https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
	t_mlx	mlx;
	int		error;

	main_init_mlx(&mlx);

	error = main_check_args(argc, argv);
	if (error <= 0)
		error = -1; // Call function error -- -1 error in args

	error = main_load_map(&mlx, argv);
	map_check(&mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.imap.width * ZOOM, mlx.imap.height * ZOOM, "The funland");

	//resize_img(&mlx);

	main_init_load_xpmfile(&mlx);
	main_init_load_image(&mlx);

	//mlx_hook(mlx.win, EVENT_KEY_PRESS, (MASK_KEY_PRESS), key_events, &mlx);
	mlx_hook(mlx.win, 2, 1L<<2, key_events, &mlx);
	
	//mlx_hook(mlx.win, EVENT_KEY_DESTROYNOTIFY, (MASK_KEY_STRUCTURENOTIFY), exit_game, &mlx);
	mlx_hook(mlx.win, 17, 1L<<17, exit_game, &mlx);
	score_print(&mlx);
	mlx_loop(mlx.mlx);

	system("leaks so_long");

	return (EXIT_SUCCESS);
}
