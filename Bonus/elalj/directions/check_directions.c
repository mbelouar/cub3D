/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:11:46 by moelalj           #+#    #+#             */
/*   Updated: 2023/12/09 23:49:03 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	ft_f(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	while (i < 6)
	{
		str = ftt_strtrim(data->map_info.str[i], "\t ");
		if (!ft_strncmp(str, "F", 1))
			data->dir.F = ftt_split(str, ' ');
		free(str);
		i++;
	}
}

void	ft_c(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	while (i < 6)
	{
		str = ftt_strtrim(data->map_info.str[i], "\t ");
		if (!ft_strncmp(str, "C", 1))
			data->dir.C = ftt_split(str, ' ');
		free(str);
		i++;
	}
}

void	check_many_directions(t_data *data)
{
	int		i;
	char	*str;

	data->c = 0;
	i = 0;
	while (i < 6)
	{
		str = ftt_strtrim(data->map_info.str[i], "\t ");
		if (!ft_strncmp(str, "NO", 2))
			data->c++;
		else if (!ft_strncmp(str, "SO", 2))
			data->c++;
		else if (!ft_strncmp(str, "WE", 2))
			data->c++;
		else if (!ft_strncmp(str, "EA", 2))
			data->c++;
		else if (!ft_strncmp(str, "F", 1))
			data->c++;
		else if (!ft_strncmp(str, "C", 1))
			data->c++;
		free(str);
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
