/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_needs_directions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:02:11 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/11 18:02:12 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_no_needs(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.NO[i])
		i++;
	if (i != 2)
		print_err_needs_directions();
}

void	check_so_needs(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.SO[i])
		i++;
	if (i != 2)
		print_err_needs_directions();
}

void	check_we_needs(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.WE[i])
		i++;
	if (i != 2)
		print_err_needs_directions();
}

void	check_ea_needs(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.EA[i])
		i++;
	if (i != 2)
		print_err_needs_directions();
}

void	check_f_needs(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.F[i])
		i++;
	if (i != 2)
		print_err_needs_directions();
}
