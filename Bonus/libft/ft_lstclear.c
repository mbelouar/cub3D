/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:45:46 by mbelouar          #+#    #+#             */
/*   Updated: 2023/10/09 16:54:52 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*p;

	if (!lst)
		return ;
	while (*lst)
	{
		p = *lst;
		*lst = (*lst)->next;
		free(p->content);
		free(p);
	}
	*lst = NULL;
}
