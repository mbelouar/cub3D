/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:11:46 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/10 00:11:47 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	f(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(data->map_info.str[i], "F", 1))
			data->dir.F = ftt_split(data->map_info.str[i], ' ');
		i++;
	}
}

void	c(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(data->map_info.str[i], "C", 1))
			data->dir.C = ftt_split(data->map_info.str[i], ' ');
		i++;
	}
}

void	check_valid_directions(t_data *data)
{
	int	i;

	data->c = 0;
	i = 0;
	while (data->map_info.str[i])
	{
		if (!ft_strncmp(data->map_info.str[i], "NO ", 3))
			data->c++;
		else if (!ft_strncmp(data->map_info.str[i], "SO ", 3))
			data->c++;
		else if (!ft_strncmp(data->map_info.str[i], "WE ", 3))
			data->c++;
		else if (!ft_strncmp(data->map_info.str[i], "EA ", 3))
			data->c++;
		else if (!ft_strncmp(data->map_info.str[i], "F ", 2))
			data->c++;
		else if (!ft_strncmp(data->map_info.str[i], "C ", 2))
			data->c++;
		i++;
	}
	if (data->c != 6)
		print_err_directions();
}

void	check_directions_needs(t_data *data)
{
	check_no_needs(data);
	check_so_needs(data);
	check_we_needs(data);
	check_ea_needs(data);
	check_f_needs(data);
	check_c_needs(data);
}

void	check_colors(t_data *data)
{
	check_f_c(data);
	check_c_c(data);
}
