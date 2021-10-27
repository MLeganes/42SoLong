/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:04:27 by amorcill          #+#    #+#             */
/*   Updated: 2021/10/27 19:51:48 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void resize_img(t_mlx *mainmlx)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	t_img	newimg;
	t_img	newimg2;

	// ini win
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	
	// // IMG create image, get data, put pixelssssss
	img.img = mlx_new_image(mlx, 10, 10);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// ft_copy_px(&img, 1,1, 0x00FF0000);
	// ft_copy_px(&img, 1,2, 0x00FF0000);
	// ft_copy_px(&img, 1,3, 0x00FF0000);
	// ft_copy_px(&img, 1,4, 0x00FF0000);
	// ft_copy_px(&img, 1,5, 0x00FF0000);
	// ft_copy_px(&img, 1,6, 0x00FF0000);
	// ft_copy_px(&img, 2,1, 0x00FF0000);
	// ft_copy_px(&img, 3,1, 0x00FF0000);
	// ft_copy_px(&img, 4,1, 0x00FF0000);
	// ft_copy_px(&img, 5,1, 0x00FF0000);
	// ft_copy_px(&img, 6,1, 0x00FF0000);
	
	
	// // load image.xpm, get info
	newimg.img = mlx_xpm_file_to_image(mlx, "./imgs/pacman50/pacmanRight.xpm", &newimg.width, &newimg.height);
	newimg.addr = mlx_get_data_addr(newimg.img, &newimg.bits_per_pixel, &newimg.line_length,
								&newimg.endian);
	
	mainmlx->map_height *= 1;
	
	// new image, put pixelsssss
		// calculate the new size.
	newimg2.img = mlx_new_image(mlx, 25, 25);
	newimg2.addr = mlx_get_data_addr(newimg2.img,&newimg2.bits_per_pixel, &newimg2.line_length,
								&newimg2.endian);
	newimg2.height = 25;
	newimg2.width = 25;
	
	// Make copy of newimg TO newimg2

	ft_create_img(&newimg2, &newimg, 2);

	// PUt the imgssssss in the win!!!!	
	//mlx_put_image_to_window(mlx, mlx_win, img.img, 10, 1);
	mlx_put_image_to_window(mlx, mlx_win, newimg.img, 100, 1);
	mlx_put_image_to_window(mlx, mlx_win, newimg2.img, 200, 1);
		
	// LOOPPPPPPPPPP
	mlx_loop(mlx);
	
	// int newx = img.height;
	// while (WIN_MAX_HEIGHT < (img.height * mainmlx->map_height) && WIN_MAX_WIDTH < img.width * mainmlx->map_width)
		//if (WIN_MAX_HEIGHT < (img.height * mainmlx->map_height) || WIN_MAX_WIDTH < img.width * mainmlx->map_width)
	//{
		//64 / 2
		//32 / 2
		//16 / 2
		//8 / 2
		//4 / 2 -- error
		//2 / 2 -- eroror
		//1		-- error
	//	newimg.img = mlx_new_image(mlx, 50, 50);  ///
		//img = newimg;
	//}

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
			// ft_copy_px(newimg, 0, 0, 0x00FF0000);
			// ft_copy_px(newimg, 35, 24, 0x00FF0000);
			// ft_copy_px(newimg, 24, 24, 0x00FF0000);
			// ft_copy_px(newimg, 24, 0, 0x00FF0000);
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