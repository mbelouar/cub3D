/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:44:02 by moelalj           #+#    #+#             */
/*   Updated: 2023/12/09 23:49:03 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	err_empty_map(void)
{
	ft_putstr_fd("Error\n  ->Tha map is empty my friend!\n", 2);
	exit (EXIT_FAILURE);
}

void	print_and_exit_param(void)
{
	ft_putstr_fd("Bad parameters input, Try again!\n", 2);
	exit (EXIT_FAILURE);
}

void	check_fd_map(int *fd, char *file)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
	{
		ft_putstr_fd("You have no file \033[1;31m", 2);
		ft_putstr_fd("aka the MAP \033[0mto read from\n", 2);
		exit (1);
	}
}
