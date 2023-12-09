/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 02:02:27 by mbelouar          #+#    #+#             */
/*   Updated: 2023/09/21 05:39:24 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

void	ft_fill_str(int size, int stock_nbrs, int n, char *str)
{
	while (size > stock_nbrs)
	{
		str[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		stock_nbrs;

	size = ft_size(n);
	stock_nbrs = 0;
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
		stock_nbrs = 2;
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		stock_nbrs = 1;
	}
	ft_fill_str(size, stock_nbrs, n, str);
	str[size] = '\0';
	return (str);
}
