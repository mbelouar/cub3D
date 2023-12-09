/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:48:15 by mbelouar          #+#    #+#             */
/*   Updated: 2022/10/11 17:05:12 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;
	size_t	len_src;
	size_t	len_dest;

	if (!dest && !destsize)
		return (0);
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (len_dest >= destsize)
		return (len_src + destsize);
	i = 0;
	j = len_dest;
	while (src[i] != '\0' && j < destsize - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (len_src + len_dest);
}
