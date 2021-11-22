/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:25:05 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/22 14:54:01 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_remove_eol(char *s)
{
	int	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == '\n')
			{
				s[i] = '\0';
				return ;
			}
			i++;
		}
	}
	return ;
}

void	ft_check_emptyline(char *line)
{
	if ((line != NULL && line[0] == '\0') || (line != NULL && line[0] == '\n'))
	{
		error_print_exit("[map error] Error read map. No empty lines in map, "
			"don't touch Pacman balls!!!");
	}	
}

void	ft_count_lines(t_mlx *mlx, char **argv)
{
	int		lines;
	char	*line;
	int		len;
	int		fd;

	lines = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		error_print_exit
		("[open file error] Error to open file!Check file.");
	line = get_next_line(fd);
	ft_check_emptyline(line);
	len = ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		ft_check_emptyline(line);
		lines++;
	}
	close(fd);
	mlx->imap.height = lines;
	mlx->imap.width = len;
}
