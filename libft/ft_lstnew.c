/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:33:27 by mbelouar          #+#    #+#             */
/*   Updated: 2023/09/29 21:33:46 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(char *content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = ft_strdup(content);
	head->next = NULL;
	return (head);
}
/*
int	main(void)
{
	t_list		*elem;

	char	str [] = "lorem ipsum dolor sit";
	int i = 1;
	elem = ft_lstnew(str);
	printf("%s", elem->content);
	return (0);
}*/
