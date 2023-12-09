/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:33:39 by moelalj           #+#    #+#             */
/*   Updated: 2023/12/09 23:49:03 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	count_words(char const *s, char delimiter)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == delimiter && s[i])
			i++;
		if (s[i])
		{
			while (s[i] != delimiter && s[i])
				i++;
			count++;
		}
	}
	return (count);
}

int	count_chars(char const *s, char delimiter, int lens)
{
	int	i;

	i = 0;
	while (s[lens] && s[lens] != delimiter)
	{
		lens++;
		i++;
	}
	return (i);
}

char	**ftt_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (0);
	str = malloc((count_words((char *)s, c) + 1) * sizeof(char *));
	if (!str)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			str[k] = ft_substr(s, i, count_chars((char *) s, c, i));
			k++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	str[k] = NULL;
	return (str);
}

void	ft_str_free(char **s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	__strchrr(char *line, char c)
{
	int		i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		if (line[i] != c)
			return (1);
		i++;
	}
	return (0);
}
