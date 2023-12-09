/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:32:53 by mbelouar          #+#    #+#             */
/*   Updated: 2022/10/18 21:46:36 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*cast_src;
	char	*cast_dest;

	cast_dest = (char *)dest;
	cast_src = (char *)src;
	if (!cast_dest && !cast_src)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cast_dest[i] = cast_src[i];
		i++;
	}
	return (dest);
}
