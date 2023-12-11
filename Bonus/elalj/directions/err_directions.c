/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_directions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:12:53 by moelalj           #+#    #+#             */
/*   Updated: 2023/12/10 00:07:16 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	check_c_needs(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.c[i])
		i++;
	if (i != 2)
		print_err_needs_directions();
}

void	print_err_directions(void)
{
	ft_putstr_fd("Eroor:\n  ->Found more/less direction in map", 2);
	exit (1);
}

void	print_err_needs_directions(void)
{
	ft_putstr_fd("Error:\n  ->invalid direction-> more/less needs", 2);
	exit (1);
}

void	found_semicolon_err(void)
{
	ft_putstr_fd("Error:\n  ->found(,)near to itself", 2);
	exit (1);
}

void	err_semicolons(void)
{
	ft_putstr_fd("Error:\n  ->found more/less semicolons", 2);
	exit (1);
}
