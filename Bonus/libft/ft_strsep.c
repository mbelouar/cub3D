/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:54:54 by mbelouar          #+#    #+#             */
/*   Updated: 2023/10/10 00:24:36 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsep(char **stringp, const char *delim)
{
	char		*token_start;
	char		*token_end;
	const char	*d;

	if (*stringp == NULL)
		return (NULL);
	token_start = *stringp;
	while (**stringp != '\0')
	{
		d = delim;
		while (*d != '\0')
		{
			if (**stringp == *d)
			{
				token_end = *stringp;
				**stringp = '\0';
				(*stringp)++;
				return (token_start);
			}
			d++;
		}
		(*stringp)++;
	}
	*stringp = NULL;
	return (token_start);
}
