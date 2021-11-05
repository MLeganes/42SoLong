/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:37:26 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/05 14:01:49 by amorcill         ###   ########.fr       */
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
			map_load_path1(mlx, w, height);
			w++;
		}
		height++;
	}
	return (0);
}

static void	main_init_load_image(t_mlx *mlx)
{
	int		wh[2];

	main_init_load_image_base(mlx);
	wh[1] = 0;
	while (wh[1] < mlx->imap.height)
	{
		wh[0] = 0;
		while (wh[0] < mlx->imap.width)
		{
			if (mlx->map[wh[1]][wh[0]] == '0')
				map_load_path1(mlx, wh[0], wh[1]);
			if (mlx->map[wh[1]][wh[0]] == '1')
				map_load_wall(mlx, wh[0], wh[1]);
			if (mlx->map[wh[1]][wh[0]] == 'P')
				map_load_init_player(mlx, wh[0], wh[1]);
			if (mlx->map[wh[1]][wh[0]] == 'C')
				collectible_load(mlx, wh[0], wh[1]);
			if (mlx->map[wh[1]][wh[0]] == 'E')
				exit_load(mlx, wh[0], wh[1]);
			if (mlx->bonus == 1 && mlx->map[wh[1]][wh[0]] == 'G')
				init_load_ghost(mlx, wh[0], wh[1]);
			wh[0]++;
		}
		wh[1]++;
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
	mlx.win = mlx_new_window
		(mlx.mlx, mlx.imap.width * ZOOM, mlx.imap.height * ZOOM, mlx.name);
	main_init_load_xpmfile(&mlx);
	main_init_load_image(&mlx);
	mlx_hook(mlx.win, 2, 1L << 2, key_events, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, exit_game, &mlx);
	score_print(&mlx);
	mlx_loop(mlx.mlx);
	system("leaks so_long");
	return (EXIT_SUCCESS);
}
