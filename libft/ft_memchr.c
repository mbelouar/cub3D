/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:36:54 by mbelouar          #+#    #+#             */
/*   Updated: 2022/10/01 01:34:49 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	size_t			i;
	unsigned char	*cast_str;

	cast_str = (unsigned char *)str;
	i = 0;
	while (i < len)
	{
		if (cast_str[i] == (unsigned char)c)
			return ((void *)&cast_str[i]);
		i++;
	}
	return (NULL);
}
