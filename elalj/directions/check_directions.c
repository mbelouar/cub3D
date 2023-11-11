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

void	check_if_double_directions(t_data *data)
{
	data->num.NO = 0;
	data->num.SO = 0;
	data->num.WE = 0;
	data->num.EA = 0;
	int	i;

	i = 0;
	while (data->map_info.str[i] != '\0')
	{
		if (!ft_strncmp(data->map_info.str[i], "NO ", 3))
			data->num.NO++;
		else if (!ft_strncmp(data->map_info.str[i], "SO ", 3))
			data->num.SO++;
		else if (!ft_strncmp(data->map_info.str[i], "WE ", 3))
			data->num.WE++;
		else if (!ft_strncmp(data->map_info.str[i], "EA ", 3))
			data->num.EA++;
		i++;
	}
	if (data->num.NO != 1 || data->num.SO != 1
		|| data->num.EA != 1 || data->num.WE != 1)
		print_err_double_dir();
}

//void	check_if_valid_direction_name(t_data *data)
//{

//}