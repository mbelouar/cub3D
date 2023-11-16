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
	no(data);
	so(data);
	we(data);
	ea(data);
	f(data);
	c(data);
}

void	no(t_data *data)
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

void	so(t_data *data)
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

void	we(t_data *data)
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

void	ea(t_data *data)
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
