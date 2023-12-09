/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:16:20 by mbelouar          #+#    #+#             */
/*   Updated: 2023/09/20 00:24:50 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*cast_str;

	i = 0;
	cast_str = (char *)str;
	while (cast_str[i] && cast_str[i] != (char)c)
		i++;
	if (cast_str[i] == (char)c)
		return (&cast_str[i]);
	return (0);
}
