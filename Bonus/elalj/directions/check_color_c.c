/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:57:39 by moelalj           #+#    #+#             */
/*   Updated: 2023/12/09 23:49:03 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	init_c_array(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.clr_c[i])
	{
		data->dir.ceiling[i] = ft_atoi(data->dir.clr_c[i]);
		i++;
	}
}

void	check_c_c(t_data *data)
{
	data->dir.clr_c = ftt_split(data->dir.C[1], ',');
	valid_box_color_c(data);
	check_consecutive_semicolon_c(data);
	valid_color_c(data);
	init_c_array(data);
}

void	check_consecutive_semicolon_c(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->dir.C[1][i])
	{
		if (data->dir.C[1][i] == ',')
		{
			i++;
			if (data->dir.C[1][i] == ',')
				found_semicolon_err();
		}
		i++;
	}
	i = 0;
	j = 0;
	while (data->dir.C[1][i])
	{
		if (data->dir.C[1][i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		err_semicolons();
}

void	valid_box_color_c(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.clr_c[i])
		i++;
	if (i != 3)
	{
		ft_putstr_fd("Error: less/more box colors\n", 2);
		ft_putstr_fd("Usage: Please enter a valid box of", 2);
		ft_putstr_fd(" colors [..],[..],[..]", 2);
		exit (1);
	}
}

void	valid_color_c(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->dir.clr_c[i])
	{
		if (ft_atoi(data->dir.clr_c[i]) > 255)
		{
			ft_putstr_fd("Error:\n  ->Please enter a number", 2);
			ft_putstr_fd("between 0 and 255", 2);
			exit (1);
		}
		j = 0;
		while (data->dir.clr_c[i][j])
		{
			if (!ft_isdigit(data->dir.clr_c[i][j]))
			{
				ft_putstr_fd("Error:\n  ->Found character in one of boxes", 2);
				exit (1);
			}
			j++;
		}
		i++;
	}
}

void	check_c_needs(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.C[i])
		i++;
	if (i != 2)
		print_err_needs_directions();
}
