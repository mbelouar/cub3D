/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:09:16 by mbelouar          #+#    #+#             */
/*   Updated: 2023/10/19 20:09:19 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*last;
	char		*token;

	if (str == NULL)
		str = last;
	while (*str != '\0' && ft_strchr(delim, *str) != NULL)
		str++;
	if (*str == '\0')
	{
		last = NULL;
		return (NULL);
	}
	token = str;
	while (*str != '\0' && ft_strchr(delim, *str) == NULL)
		str++;
	if (*str != '\0')
	{
		*str = '\0';
		str++;
	}
	last = str;
	return (token);
}
