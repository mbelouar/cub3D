/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_directions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:03:56 by moelalj           #+#    #+#             */
/*   Updated: 2023/12/10 00:07:18 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	init_directions(t_data *data)
{
	ft_no(data);
	ft_so(data);
	ft_we(data);
	ft_ea(data);
	ft_f(data);
	ft_c(data);
}

void	ft_no(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	while (i < 6)
	{
		str = ftt_strtrim(data->map_info.str[i], "\t ");
		if (!ft_strncmp(str, "NO", 2))
			data->dir.NO = ftt_split(str, ' ');
		free(str);
		i++;
	}
}

void	ft_so(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	while (i < 6)
	{
		str = ftt_strtrim(data->map_info.str[i], "\t ");
		if (!ft_strncmp(str, "SO", 2))
			data->dir.SO = ftt_split(str, ' ');
		free(str);
		i++;
	}
}

void	ft_we(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	while (i < 6)
	{
		str = ftt_strtrim(data->map_info.str[i], "\t ");
		if (!ft_strncmp(str, "WE", 2))
			data->dir.WE = ftt_split(str, ' ');
		free(str);
		i++;
	}
}

void	ft_ea(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	while (i < 6)
	{
		str = ftt_strtrim(data->map_info.str[i], "\t ");
		if (!ft_strncmp(str, "EA", 2))
			data->dir.EA = ftt_split(str, ' ');
		free(str);
		i++;
	}
}
