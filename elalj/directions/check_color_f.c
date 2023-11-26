/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:59:49 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/11 20:59:52 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_f_array(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.clr_f[i])
	{
		data->dir.floor[i] = ft_atoi(data->dir.clr_f[i]);
		i++;
	}
}
void	check_f_c(t_data *data)
{
	data->dir.clr_f = ftt_split(data->dir.F[1], ',');
	valid_box_color_f(data);
	check_consecutive_semicolon_f(data);
	valid_color_f(data);
	init_f_array(data);
}

void	check_consecutive_semicolon_f(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->dir.F[1][i])
	{
		if (data->dir.F[1][i] == ',')
		{
			i++;
			if (data->dir.F[1][i] == ',')
				found_semicolon_err();
		}
		i++;
	}
	i = 0;
	j = 0;
	while (data->dir.F[1][i])
	{
		if (data->dir.F[1][i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		err_semicolons();
}

void	valid_box_color_f(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.clr_f[i])
		i++;
	if (i != 3)
	{
		ft_putstr_fd("Error: less/more box colors\n", 2);
		ft_putstr_fd("Usage: Please enter a valid box of", 2);
		ft_putstr_fd(" colors [..],[..],[..]", 2);
		exit (1);
	}
}

void	valid_color_f(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->dir.clr_f[i])
	{
		if (ft_atoi(data->dir.clr_f[i]) > 255)
		{
			ft_putstr_fd("Error:\n  ->Please enter a number", 2);
			ft_putstr_fd(" between 0 and 255", 2);
			exit (1);
		}
		j = 0;
		while (data->dir.clr_f[i][j])
		{
			if (!ft_isdigit(data->dir.clr_f[i][j]))
			{
				ft_putstr_fd("Error:\n  ->Found character in one of boxes", 2);
				exit (1);
			}
			j++;
		}
		i++;
	}
}
