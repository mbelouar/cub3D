/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_directions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:12:53 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/10 00:12:54 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	print_err_NO()
{
	ft_putstr_fd("Attention! Error with some of directions in map", 2);
	ft_putstr_fd(" <NORTH>", 2);
	exit (1);
}

void	print_err_SO()
{
	ft_putstr_fd("Attention! Error with some of directions in map", 2);
	ft_putstr_fd(" <SOUTH>", 2);
	exit (1);
}

void	print_err_WE()
{
	ft_putstr_fd("Attention! Error with some of directions in map", 2);
	ft_putstr_fd(" <WEST>", 2);
	exit (1);
}

void	print_err_EA()
{
	ft_putstr_fd("Attention! Error with some of directions in map", 2);
	ft_putstr_fd(" <EAST>", 2);
	exit (1);
}

void	print_err_double_dir()
{
	ft_putstr_fd("Found double/missing direction in map", 2);
	exit (1);
}
