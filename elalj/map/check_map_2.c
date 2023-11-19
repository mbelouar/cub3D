/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:34:36 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/17 17:34:37 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	found_last_0(char *line)
{
	int	j;

	j = 0;
	while (line[j])
		j++;
	j--;
	while (j != 0)
	{
		if (line[j] == '0')
			return (j);
		j--;
	}
	return (0);
}

void	check_if_play_can_go_bg(t_data *data)
{
	int	i;
	int	l_0;
	int	p_len;
	int	n_len;

	i = 1;
	while (data->map_info.map_wt[i])
	{
		p_len = ftt_strlen(data->map_info.map_wt[i - 1]);
		l_0 = found_last_0(data->map_info.map_wt[i]);
		if (data->map_info.map_wt[i + 1])
			n_len = ftt_strlen(data->map_info.map_wt[i + 1]);
		if (l_0 >= p_len || l_0 >= n_len)
		{
			ft_putstr_fd("Error:\n  ->Player can go to bg\n", 2);
			exit (1);
		}
		i++;
	}
}
