/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_casses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:10:51 by moelalj           #+#    #+#             */
/*   Updated: 2023/12/09 23:49:03 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	check_around_spaces(t_data *data)
{
	int		i;
	char	**str;

	i = 0;
	str = malloc(sizeof(char *) * data->map_info.columns - 6);
	if (!str)
		return ;
	while (data->map_info.map_wt[i])
	{
		str[i] = ft_strdup(data->map_info.map_wt[i]);
		i++;
	}
	str[i] = NULL;
	start_checking_around_spaces(str);
	ft_str_free(str);
}

void	start_checking_around_spaces(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[0][j] == ' ')
				if (str[1][j] != '1' && str[1][j] != ' ')
					around_spaces_err();
			if (str[i + 1] == NULL && str[i][j] == ' ')
				if (str[i - 1][j] != '1' && str[i - 1][j] != ' ')
					around_spaces_err();
			if (str[i][j] == ' ' && i != 0 && str[i + 1])
				ch_inside_map(str, i, j);
			j++;
		}
		i++;
	}
}

void	ch_inside_map(char **str, int i, int j)
{
	if ((str[i - 1][j] != '1' && str[i - 1][j] != ' ')
		|| (str[i + 1][j] != '1' && str[i + 1][j] != ' ')
		|| (str[i][j - 1] != '1' && str[i][j - 1] != ' ')
		|| (str[i][j + 1] != '1' && str[i][j + 1] != ' '))
		around_spaces_err();
}
