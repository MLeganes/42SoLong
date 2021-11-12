/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:19:32 by amorcill          #+#    #+#             */
/*   Updated: 2021/11/12 16:36:34 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_print_exit(char *error_msg)
{	
	printf("Error\n");
	printf("%s \n", error_msg);
	exit (EXIT_FAILURE);
}
