/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratojo <maratojo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:13:09 by maratojo          #+#    #+#             */
/*   Updated: 2026/02/08 16:13:21 by maratojo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*a;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		a = temp -> next;
		ft_lstdelone(temp, del);
		temp = a;
	}
	*lst = NULL;
}
