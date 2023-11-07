/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:19:03 by mbelouar          #+#    #+#             */
/*   Updated: 2022/10/11 15:23:18 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	char	*cast_str;
	size_t	i;

	i = 0;
	cast_str = (char *)str;
	while (i < len)
	{
		cast_str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
