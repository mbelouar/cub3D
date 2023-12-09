/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:45:55 by mbelouar          #+#    #+#             */
/*   Updated: 2022/10/14 15:49:20 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*cast_src;
	unsigned char	*cast_dest;

	cast_dest = (unsigned char *)dest;
	cast_src = (unsigned char *)src;
	if (cast_dest > cast_src)
	{
		while (len--)
			cast_dest[len] = cast_src[len];
	}
	else
		ft_memcpy(cast_dest, cast_src, len);
	return (dest);
}
