/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:44:02 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/07 15:20:58 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_and_exit_param(void)
{
	ft_putstr_fd("Bad parameters input, Try again!", 2);
	exit (EXIT_FAILURE);
}

void	open_fd_check(int *fd, char *file)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
	{
		ft_putstr_fd("You have no file to read from", 1);
		exit (EXIT_FAILURE);
	}
}
