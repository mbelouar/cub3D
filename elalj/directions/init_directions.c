/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_directions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:03:56 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/11 17:03:57 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_directions(t_data *data)
{
	NO(data);
	SO(data);
	WE(data);
	EA(data);
	F(data);
	C(data);
}

void	NO(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(data->map_info.str[i], "NO", 2))
			data->dir.NO = ftt_split(data->map_info.str[i], ' ');
		i++;
	}
}
void	SO(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(data->map_info.str[i], "SO", 2))
			data->dir.SO = ftt_split(data->map_info.str[i], ' ');
		i++;
	}
}
void	WE(t_data *data)
{
		int	i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(data->map_info.str[i], "WE", 2))
			data->dir.WE = ftt_split(data->map_info.str[i], ' ');
		i++;
	}
}
void	EA(t_data *data)
{
		int	i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(data->map_info.str[i], "EA", 2))
			data->dir.EA = ftt_split(data->map_info.str[i], ' ');
		i++;
	}
}
void	F(t_data *data)
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
void	C(t_data *data)
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
