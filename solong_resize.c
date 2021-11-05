/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:04:27 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/05 16:01:56 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void resize_img(t_mlx *mainmlx)
{
	void	*mlx;
	void	*mlx_win;
	t_img	newimg;
	t_img	newimg2;
		
	mainmlx->imap.height *= 1;
	
	// ini win
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	
	newimg.img = mlx_xpm_file_to_image(mlx, "./imgs/pacmanRight.xpm", &newimg.width, &newimg.height);
	newimg.addr = mlx_get_data_addr(newimg.img, &newimg.bits_per_pixel, &newimg.line_length,
								&newimg.endian);
				
	newimg2.img = mlx_new_image(mlx, 32, 32);
	newimg2.addr = mlx_get_data_addr(newimg2.img,&newimg2.bits_per_pixel, &newimg2.line_length,
								&newimg2.endian);
	newimg2.height = 32;
	newimg2.width = 32;
	
	// Reduce half size of the actual picture.
	ft_create_img(&newimg2, &newimg, 2);		
	
	// PUt the imgssssss in the win!!!!	
	mlx_put_image_to_window(mlx, mlx_win, newimg.img, 100, 1);
	mlx_put_image_to_window(mlx, mlx_win, newimg2.img, 200, 1);
		
	// LOOPPPPPPPPPP
	mlx_loop(mlx);
}

void ft_create_img(t_img *newimg, t_img *oldimg, int scale)
{	
	int	x;
	int y;
	unsigned int color;

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
	*(unsigned int*)dst = color;
}