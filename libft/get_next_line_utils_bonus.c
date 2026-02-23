/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finorako <finorako@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 09:55:22 by finorako          #+#    #+#             */
/*   Updated: 2026/02/06 10:23:24 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include <stdlib.h>

void	lstadd(t_line_list **lst, char *content)
{
	t_line_list	*new_lst;
	t_line_list	*last;

	if (!content || *content == '\0')
		return ;
	new_lst = (t_line_list *)malloc(sizeof(t_line_list));
	if (!new_lst)
		return ;
	new_lst->content = content;
	new_lst->next = NULL;
	if (*lst == NULL)
	{
		*lst = new_lst;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new_lst;
}

int	found_endl(t_line_list *lst)
{
	int	index;

	while (lst)
	{
		index = 0;
		while (lst->content[index] && lst->content[index] != '\n')
			index++;
		if (lst->content[index] == '\n')
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	line_size(t_line_list *lst)
{
	t_line	line;

	line.i = 0;
	while (lst)
	{
		line.j = 0;
		while (lst->content[line.j] && lst->content[line.j] != '\n')
		{
			line.i++;
			line.j++;
		}
		if (lst->content[line.j] == '\n')
			return (++line.i);
		lst = lst->next;
	}
	return (line.i);
}

int	get_next(char *content)
{
	int	index;

	index = 0;
	while (content[index] && content[index] != '\n')
		index++;
	if (content[index] == '\n')
		return (++index);
	return (-1);
}
