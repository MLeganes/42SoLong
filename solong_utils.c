
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
