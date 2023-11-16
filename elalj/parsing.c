/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:56:57 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/16 15:44:48 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	found_player_n_s(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_info.map_wt[i])
	{
		j = 0;
		while (data->map_info.map_wt[i][j])
		{
			if (data->map_info.map_wt[i][j] == 'N')
			{
				data->map_info.snew_dir = 'N';
				data->map_info.snew_x = i;
				data->map_info.snew_y = j;
			}
			if (data->map_info.map_wt[i][j] == 'S')
			{
				data->map_info.snew_dir = 'S';
				data->map_info.snew_x = i;
				data->map_info.snew_y = j;
			}
			j++;
		}
		i++;
	}
}

void	found_player_e_w(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_info.map_wt[i])
	{
		j = 0;
		while (data->map_info.map_wt[i][j])
		{
			if (data->map_info.map_wt[i][j] == 'E')
			{
				data->map_info.snew_dir = 'E';
				data->map_info.snew_x = i;
				data->map_info.snew_y = j;
			}
			if (data->map_info.map_wt[i][j] == 'W')
			{
				data->map_info.snew_dir = 'W';
				data->map_info.snew_x = i;
				data->map_info.snew_y = j;
			}
			j++;
		}
		i++;
	}
}

int	map_valid(t_data *data, int fd, char *file)
{
	check_extension_map(file);
	read_map(data, fd);
	check_valid_directions(data);
	init_directions(data);
	check_directions_needs(data);
	check_colors(data);
	init_maps(data);
	check_map(data);
	found_player_n_s(data);
	found_player_e_w(data);
	printf("%c\n", data->map_info.snew_dir);
	printf("%d\n", data->map_info.snew_x);
	printf("%d\n", data->map_info.snew_y);
	return (1);
}
