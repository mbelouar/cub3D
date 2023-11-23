/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_directions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:12:53 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/23 20:47:24 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	print_err_directions(void)
{
	ft_putstr_fd("Eroor:\n  ->Found double/missing direction in map", 2);
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
