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

void    check_f_c(t_data *data)
{
	check_consecutive_semicolon_f(data);
	data->dir.clr_f = ftt_split(data->dir.F[1], ',');
	valid_box_color_f(data);
	valid_color_f(data);
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
			if(data->dir.F[1][i] == ',')
			{
				ft_putstr_fd("Error: found(,)near to itself", 2);
				exit (1);
			}
		}
		i++;
	}
	i = 0;
	j = 0;
	while(data->dir.F[1][i])
	{
		if (data->dir.F[1][i] == ',')
			j++;
		i++;
	}
	if (j != 2)
	{
		ft_putstr_fd(" xz found more/less semicolons", 2);
		exit (1);
	}
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
		ft_putstr_fd("Usage: Please enter a valid box of colors [..],[..],[..]", 2);
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
			ft_putstr_fd("Please enter a number between 0 and 255", 2);
			exit (1);
		}
		j = 0;
		while (data->dir.clr_f[i][j])
		{
			if (!ft_isdigit(data->dir.clr_f[i][j]))
			{
				ft_putstr_fd("Error: found character in one of boxes", 2);
				exit (1);
			}
			j++;
		}
		i++;
	}
}