/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_strtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:11:12 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/19 17:11:33 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check(char ch, char const *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (ch == set[j])
			return (0);
		j++;
	}
	return (1);
}

int	check_start(char const *s, char const *set)
{
	int	count_start;

	count_start = 0;
	while (s[count_start] != '\0')
	{
		if (check(s[count_start], set) == 0)
			count_start++;
		else
			return (count_start);
	}
	return (0);
}

int	check_end(char const *s, char const *set)
{
	int	len_s;
	int	count_end;

	len_s = ft_strlen(s) - 1;
	count_end = len_s;
	while (count_end >= 0)
	{
		if (check(s[count_end], set) == 0)
			count_end--;
		else
			return (count_end);
	}
	return (0);
}

char	*ftt_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;
	int	len;

	if (!s1)
		return (0);
	start = check_start(s1, set);
	end = check_end(s1, set);
	len = end - start;
	if (len <= 0)
		return ("\0");
	return (ft_substr(s1, start, len + 1));
}
