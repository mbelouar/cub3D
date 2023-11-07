/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:35:53 by mbelouar          #+#    #+#             */
/*   Updated: 2022/10/10 16:03:39 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	substring = (char *)malloc(sizeof(char) * len + 1);
	if (!substring)
		return (NULL);
	if (start <= ft_strlen(s))
	{
		while (i < len && s[start] != '\0')
		{
			substring[i] = s[start];
			i++;
			start++;
		}
		substring[i] = '\0';
	}
	else
		substring[0] = '\0';
	return (substring);
}
