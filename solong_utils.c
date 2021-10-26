
#include "so_long.h"

void ft_remove_eol(char *s)
{
	int i;

	if (s != NULL)
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == '\n')
			{
				s[i] = '\0';
				return;
			}
			i++;
		}
	}
	return ;
}

int ft_count_lines(t_mlx *mlx, char **argv)
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
	ft_remove_eol(line);	
	len = ft_strlen(line);
	while(line)
	{
		free(line);
		line = get_next_line(fd);				
		lines++;
	}
	close(fd);	
	
	mlx->map_height = lines;	
	mlx->map_width = len;
	return (1);
}