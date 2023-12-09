/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:30:29 by mbelouar          #+#    #+#             */
/*   Updated: 2023/10/10 16:13:58 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_array_to_lst(char **arr)
{
	int		i;
	t_list	*lst;
	t_list	*node;

	lst = NULL;
	node = NULL;
	i = -1;
	while (arr[++i])
	{
		node = ft_lstnew(arr[i]);
		if (node == NULL)
			return (NULL);
		ft_lstadd_back(&lst, node);
	}
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
	return (lst);
}

t_list	*ft_split_lst(char const *s, char c)
{
	char	**dest;
	int		count_word;

	if (!s)
		return (NULL);
	count_word = ft_count_words(s);
	dest = malloc(sizeof(char *) * (count_word + 1));
	if (!dest)
		return (NULL);
	fill_s(dest, s, c, count_word);
	return (ft_array_to_lst(dest));
}
