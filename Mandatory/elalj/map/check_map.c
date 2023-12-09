/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:51:21 by moelalj           #+#    #+#             */
/*   Updated: 2023/12/10 00:07:38 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	found_tab_inside(t_data *data)
{
	int		i;

	i = 0;
	while (data->map_info.map_wt[i])
	{
		if (ftt_strchr(data->map_info.map_wt[i], '\t'))
		{
			ft_putstr_fd("Error\n  ->Found tab inside tha map\n", 2);
			exit (1);
		}
		i++;
	}
}

void	only_valid_characters(t_data *data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (data->map_info.map_wt[i])
	{
		str = ft_strdup(data->map_info.map_wt[i]);
		j = 0;
		while (str[j])
		{
			if (str[j] != '1' && str[j] != '0'
				&& str[j] != 'N' && str[j] != ' '
				&& str[j] != 'S' && str[j] != 'W'
				&& str[j] != 'E')
			{
				ft_putstr_fd("Error\n  ->Found a forbidden character.\n", 2);
				exit (1);
			}
			j++;
		}
		free(str);
		i++;
	}
}

void	check_surr_by_walls(t_data *data)
{
	int	i;
	int	len;

	i = 1;
	if (__strchrr(data->map_info.map_wt[0], '1'))
		not_surr_err();
	while (data->map_info.map_wt[i])
	{
		len = ftt_strlen(data->map_info.map_wt[i]);
		if (ft_strncmp(data->map_info.map_wt[i], "1", 1))
			not_surr_err();
		if (data->map_info.map_wt[i][len - 1] != '1')
			not_surr_err();
		i++;
	}
	if (__strchrr(data->map_info.map[i - 1], '1'))
		not_surr_err();
}

void	check_if_float_directions(t_data *data)
{
	int	i;
	int	c;
	int	j;

	c = 0;
	i = 0;
	while (data->map_info.map[i])
	{
		j = 0;
		while (data->map_info.map[i][j])
		{
			if (data->map_info.map[i][j] == 'N'
				|| data->map_info.map[i][j] == 'S'
				|| data->map_info.map[i][j] == 'W'
				|| data->map_info.map[i][j] == 'E')
				c++;
			j++;
		}
		i++;
	}
	if (c == 0)
		non_directions_err();
	if (c != 1)
		float_directions_err();
}

void	check_map(t_data *data)
{
	found_tab_inside(data);
	only_valid_characters(data);
	check_if_float_directions(data);
	check_surr_by_walls(data);
	check_around_spaces(data);
	check_if_play_can_go_bg(data);
}
