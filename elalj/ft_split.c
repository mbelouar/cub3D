/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:33:39 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/09 20:51:56 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
