/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:20:31 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/09 19:18:06 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*ftt_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
char	*ftt_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 && !s2)
		return (0);
	str = malloc((ftt_strlen(s1) + ftt_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	ftt_strcpy(str, s1);
	i = 0;
	while (s2[i] != '\0')
	{
		str[ftt_strlen(s1) + i] = s2[i];
		i++;
	}
	str[ftt_strlen(s1) + i] = '\0';
	free(s1);
	return (str);
}

char	*ftt_strchr(const char *s, int c)
{
	int		i;
	char	pc;

	if (!s)
		return (0);
	pc = c;
	i = 0;
	while (1)
	{
		if (s[i] == pc)
			return ((char *)&s[i]);
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

size_t	ftt_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
