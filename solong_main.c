/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: x250 <x250@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:37:26 by amorcill          #+#    #+#             */
/*   Updated: 2021/10/22 00:05:12 by x250             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <so_long.>
#include "so_long.h"

static int ft_count_lines(t_mlx *mlx, char **argv)
{
	int lines;
	char *line;
	int len;
	int fd;
	
	lines = 0;
	fd = open(argv[1], O_RDONLY);
	if( fd <= 0)
		return (-2);
	line = get_next_line(fd);
	len = ft_strlen(line);
	while(line)
	{
		free(line);
		line = get_next_line(fd);		
		lines++;
	}
	close(fd);	
	mlx->img_height = lines;
	mlx->img_width = len -1;
	return (1);
}

static int main_check_args(int args, char **argv)
{
	int		error;
	char	*ret;
	char 	aux[255];
	int		i;
	
	error = -1;
	if( args == 2 )
	{
		ret = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));		
		i = 0;
		while(argv[1][i])
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

static void ft_remove_eol(char *s)
{
	int i;
	
	i =0;
	while(s[i])
	{
		if( s[i] == '\n')
		{
			s[i] = '\0';
			return ;	
		}
		i++;
	}
}

/*
 * Load the map.ber. Read the file and save the lines.
 */
static int		main_load_map(t_mlx *mlx, char **argv)
{	
	int		lines;
	char 	*line;
	int 	fd;
	int		aux;

	// malloc the pointers to the array
	ft_count_lines(mlx, argv);
	lines = mlx->img_height;
	mlx->map = (char **)malloc( lines * (sizeof(char *)));
	if(mlx->map == NULL)
		return (-8);
	fd = open(argv[1], O_RDONLY);
	if( fd <= 0)
		return (-2);// Call func. -2 error in open file
	line = get_next_line(fd);
	lines = 0;
	while(line)
	{
		ft_remove_eol(line);
		mlx->map[lines] = line;
		line = get_next_line(fd);				
		lines++;
	}	
	if (close(fd) < 0)
		return(-4);		
	return (1);
}

static int main_init_load_xpmfile(t_mlx *mlx)
{
	mlx->pointer_path 	= mlx_xpm_file_to_image(mlx->mlx, "./imgs/path.xpm" , &mlx->x, &mlx->y);
	mlx->pointer_wall 	= mlx_xpm_file_to_image(mlx->mlx, "./imgs/wall.xpm", &mlx->x, &mlx->y);
	mlx->pointer_player1 = mlx_xpm_file_to_image(mlx->mlx, "./imgs/player.xpm", &mlx->x, &mlx->y);
	mlx->pointer_exit 	= mlx_xpm_file_to_image(mlx->mlx, "./imgs/exit.xpm", &mlx->x, &mlx->y);
	mlx->pointer_collect = mlx_xpm_file_to_image(mlx->mlx, "./imgs/collect.xpm", &mlx->x, &mlx->y);
	mlx->pointer_bomb = mlx_xpm_file_to_image(mlx->mlx, "./imgs/bomb.xpm", &mlx->x, &mlx->y);
	return (1);
}	

static int  main_init_load_image_base(t_mlx *mlx)
{
	//array 
	int height;
	int w;
	char aux;
	
	height = 0;
	w = 0;
	while(height < mlx->img_height)
	{
		w = 0;
		while (w < mlx->img_width)
		{
			aux = mlx->map[height][w];
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pointer_path,	w * ZOOM, height * ZOOM);
			w++;
		}
		height++;
	}
	return (0);
}

static int main_init_load_image(t_mlx *mlx)
{
	//array
	int height;
	int w;
	char aux;
	
	main_init_load_image_base(mlx);
	
	height = 0;
	w = 0;
	while(height < mlx->img_height)
	{
		w = 0;
		while (w < mlx->img_width  )
		{
			aux = mlx->map[height][w];
			if(mlx->map[height][w] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pointer_path,	w * ZOOM, height * ZOOM);
			if(mlx->map[height][w] == '1' )
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pointer_wall,	w * ZOOM, height * ZOOM);
			if(mlx->map[height][w] == 'P' )
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pointer_player1,	w * ZOOM, height * ZOOM);
				mlx->player1_horizontal = w;
				mlx->player1_vertical = height;				
			}
			if(mlx->map[height][w] == 'C' )
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pointer_collect,	w * ZOOM, height * ZOOM);
				collectible_increase(mlx);
				
			}
			if(mlx->map[height][w] == 'E' )
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pointer_exit,	w * ZOOM, height * ZOOM);
			w++;
		}
		height++;
	}
	return (0);
}

int main (int argc, char **argv)
{
	//https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
	t_mlx	mlx;
	int		error;

	error = main_check_args(argc, argv);
	if ( error <= 0)
		error = -1;// Call function error -- -1 error in args	
	error = main_load_map(&mlx, argv);
	map_check(&mlx);	
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.img_width * ZOOM, mlx.img_height * ZOOM, "The funland");
	
	error = main_init_load_xpmfile(&mlx);
	error = main_init_load_image(&mlx);
	//mlx_hook(mlx.win, )
	mlx_hook(mlx.win, EVENT_KEY_PRESS, (MASK_KEY_PRESS), key_events, &mlx);
	mlx_hook(mlx.win, EVENT_KEY_DESTROYNOTIFY, (MASK_KEY_STRUCTURENOTIFY), exit_game, &mlx);
	

	mlx_loop(mlx.mlx);

	return(0);
}	
