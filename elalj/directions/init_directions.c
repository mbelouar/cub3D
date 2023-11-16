/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_directions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:03:56 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/16 16:52:58 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_directions(t_data *data)
{
	ft_NO(data);
	ft_SO(data);
	ft_WE(data);
	ft_EA(data);
	ft_F(data);
	ft_C(data);
}

void	ft_NO(t_data *data)
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

void	ft_SO(t_data *data)
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

void	ft_WE(t_data *data)
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

void	ft_EA(t_data *data)
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
