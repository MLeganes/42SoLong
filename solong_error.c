/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:19:32 by amorcill          #+#    #+#             */
/*   Updated: 2021/10/22 11:13:26 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error_print_exit(char *error_msg)
{
	perror("Error\n");
	perror(error_msg);
	//perror("\n");	
	//printf("what is exit failure: %d ", EXIT_FAILURE);
	//exit (EXIT_FAILURE);
	exit (1);
}