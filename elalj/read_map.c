/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:47:12 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/09 18:47:13 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	read_map(t_data *data, int fd)
{
	char *fullmap;
	char *line;

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