/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:47:12 by moelalj           #+#    #+#             */
/*   Updated: 2023/12/10 00:07:59 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_map_wt(t_data *data)
{
	int	i;
	int	columns;

	i = 0;
	columns = 6;
	while (data->map_info.str[columns])
	{
		data->map_info.map_wt[i] = ft_strtrim(data->map_info.str[columns], "\t");
		i++;
		columns++;
	}
	data->map_info.map_wt[i] = NULL;
}

void	init_map(t_data *data)
{
	int	i;
	int	columns;

	i = 0;
	columns = 6;
	while (data->map_info.str[columns])
	{
		data->map_info.map[i] = ft_strdup(data->map_info.str[columns]);
		i++;
		columns++;
	}
	data->map_info.map[i] = NULL;
}

void	init_maps(t_data *data)
{
	data->map_info.columns = 0;
	while (data->map_info.str[data->map_info.columns])
		data->map_info.columns++;
	data->map_info.map = malloc(sizeof(char *) * data->map_info.columns - 6);
	if (!data->map_info.map)
		return ;
	data->map_info.map_wt = malloc(sizeof(char *) * data->map_info.columns - 6);
	if (!data->map_info.map_wt)
		return ;
	init_map(data);
	init_map_wt(data);
}

void	check_extension_map(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	i--;
	if (file[i] != 'b')
		extension_err();
	if (file[i - 1] != 'u')
		extension_err();
	if (file[i - 2] != 'c')
		extension_err();
	if (file[i - 3] != '.')
		extension_err();
	if ((i - 4 - 4) == 0)
	{
		ft_putstr_fd("Error\n  ->No file name!\n", 2);
		exit (1);
	}
}

void	read_map(t_data *data, int fd)
{
	char	*fullmap;
	char	*line;

	fullmap = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		err_empty_map();
	while (line != NULL)
	{
		fullmap = ftt_strjoin(fullmap, line);
		free(line);
		line = get_next_line(fd);
	}
	data->map_info.str = ftt_split(fullmap, '\n');
	free(fullmap);
}
