/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:37:26 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/04 20:58:48 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	main_check_args(int args, char **argv)
{
	char	*ret;

	if (args == 2)
	{
		ret = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
		if (ret == NULL)
			error_print_exit("[args error] Error to read arguments!");
		return ;
	}
	else
	{
		error_print_exit("[args error] Exceded the number of arguments!");
	}
}

/*
 * Load the map.ber. Read the file and save the lines.
 */



static void	main_init_load_xpmfile(t_mlx *mlx)
{
	main_load_image_map(mlx);
	main_load_image_player(mlx);
	if (mlx->bonus == 1)
		load_image_ghost(mlx);
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
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PATH_1]
				.img, w * ZOOM, height * ZOOM);
			w++;
		}
		height++;
	}
	return (0);
}

static void	main_init_load_image(t_mlx *mlx)
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
					mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PLAY_D].img, w * ZOOM, height * ZOOM);
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
			if (mlx->bonus == 1 && mlx->map[height][w] == 'G')
			{
				init_load_ghost(mlx, w, height);
				//mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[IMG_PINK].img, w * ZOOM, height * ZOOM);
			}
			w++;
		}
		height++;
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	
	mlx.bonus = BONUS;
	main_init_mlx(&mlx);
	main_check_args(argc, argv);
	main_load_map(&mlx, argv);
	map_check(&mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.imap.width * ZOOM, mlx.imap.height * ZOOM, mlx.name);
	main_init_load_xpmfile(&mlx);
	main_init_load_image(&mlx);
	mlx_hook(mlx.win, 2, 1L << 2, key_events, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, exit_game, &mlx);
	score_print(&mlx);
	mlx_loop(mlx.mlx);
	system("leaks so_long");
	return (EXIT_SUCCESS);
}
