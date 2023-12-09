/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:06:02 by mbelouar          #+#    #+#             */
/*   Updated: 2023/10/23 01:38:52 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final_str;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL)
		s1 = ft_calloc(1, sizeof(char));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	j = 0;
	final_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!final_str)
		return (NULL);
	while (i < len_s1)
		final_str[j++] = s1[i++];
	i = 0;
	while (i < len_s2)
		final_str[j++] = s2[i++];
	final_str[j] = '\0';
	free((void *)s1);
	return (final_str);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*final_str;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL)
		s1 = ft_calloc(1, sizeof(char));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	j = 0;
	final_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!final_str)
		return (NULL);
	while (i < len_s1)
		final_str[j++] = s1[i++];
	i = 0;
	while (i < len_s2)
		final_str[j++] = s2[i++];
	final_str[j] = '\0';
	return (final_str);
}
