/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:37:26 by amorcill          #+#    #+#             */
/*   Updated: 2021/09/27 13:54:54 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int main (int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;

	if ( argc == 2 && argv)
	{
		//do somethign
	}
		

	mlx = mlx_init();

	mlx_win = mlx_new_window(
		mlx,
		1920,
		1080,
		"Hello World"
	);
	

	return (0);	
}