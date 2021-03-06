/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:04:27 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/22 15:36:55 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	resize_img(t_mlx *mainmlx)
{
	void	*mlx;
	void	*mlx_win;
	t_img	newimg;
	t_img	newimg2;

	mainmlx->imap.height *= 1;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	newimg.img = mlx_xpm_file_to_image(mlx, "./imgs/pacmanRight.xpm",
			&newimg.width, &newimg.height);
	newimg.addr = mlx_get_data_addr(newimg.img, &newimg.bits_per_pixel,
			&newimg.line_length, &newimg.endian);
	newimg2.img = mlx_new_image(mlx, 32, 32);
	newimg2.addr = mlx_get_data_addr(newimg2.img, &newimg2.bits_per_pixel,
			&newimg2.line_length, &newimg2.endian);
	newimg2.height = 32;
	newimg2.width = 32;
	ft_create_img(&newimg2, &newimg, 2);
	mlx_put_image_to_window(mlx, mlx_win, newimg.img, 100, 1);
	mlx_put_image_to_window(mlx, mlx_win, newimg2.img, 200, 1);
	mlx_loop(mlx);
}

void	ft_create_img(t_img *newimg, t_img *oldimg, int scale)
{	
	int				x;
	int				y;
	unsigned int	color;

	x = 0;
	while (x < newimg->height)
	{
		y = 0;
		while (y < newimg->width)
		{			
			color = *(unsigned int *)(oldimg->addr
					+ (unsigned int)(y * oldimg->line_length * scale
						+ x * scale * (oldimg->bits_per_pixel / 8)));
			ft_copy_px(newimg, x, y, color);
			y++;
		}
		x++;
	}
}

void	ft_copy_px(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_maximum_screen(t_mlx *mlx)
{	
	if (mlx->imap.height * mlx->imgs[0].height > WIN_MAX_HEIGHT
		|| mlx->imap.width * mlx->imgs[0].width > WIN_MAX_WIDTH)
	{
		error_print_exit("[map error] Pacman can not play,"
			" is lost in the screen!!!");
	}
}
