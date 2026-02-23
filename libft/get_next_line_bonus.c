/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finorako <finorako@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 07:41:42 by finorako          #+#    #+#             */
/*   Updated: 2026/02/06 10:23:52 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

static int	len(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		index++;
	}
	return (index);
}

static char	*get_line(t_line_list *lst)
{
	t_line	line;

	if (!lst)
		return (NULL);
	line.value = (char *)malloc(sizeof(char) * (line_size(lst) + 1));
	if (!line.value)
		return (NULL);
	line.i = 0;
	while (lst)
	{
		line.j = 0;
		while (lst->content[line.j] && lst->content[line.j] != '\n')
			line.value[line.i++] = lst->content[line.j++];
		if (lst->content[line.j] == '\n')
		{
			line.value[line.i++] = '\n';
			break ;
		}
		lst = lst->next;
	}
	line.value[line.i] = '\0';
	return (line.value);
}

static char	*sub_dup(char *buffer, int size, int can_free)
{
	t_line	line;

	line.value = (char *)malloc(sizeof(char) * (size + 1));
	if (!line.value)
		return (NULL);
	line.i = 0;
	while (line.i < size)
	{
		line.value[line.i] = buffer[line.i];
		line.i++;
	}
	line.value[line.i] = '\0';
	if (can_free)
		free(buffer);
	return (line.value);
}

void	cleanlst(t_line_list **lst, char *remain)
{
	t_current	curr;

	if (!lst || !*lst)
		return ;
	while ((*lst)->next)
	{
		curr.temp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = curr.temp;
	}
	remain[0] = '\0';
	if ((*lst)->content)
	{
		curr.start = get_next((*lst)->content);
		if (curr.start >= 0)
			ft_memmove(remain, (*lst)->content + curr.start,
				len((*lst)->content + curr.start) + 1);
	}
	else
		remain[0] = '\0';
	free((*lst)->content);
	free(*lst);
	*lst = NULL;
}

char	*get_next_line(int fd)
{
	static t_start	start[MAX_FD] = {{NULL, NULL, {0}, 0}};
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	if (start[fd].last[0] != '\0')
		lstadd(&start[fd].lst, sub_dup(start[fd].last, len(start[fd].last), 0));
	while (!found_endl(start[fd].lst))
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			break ;
		start[fd].b_read = read(fd, buffer, BUFFER_SIZE);
		if (start[fd].b_read <= 0)
		{
			free(buffer);
			break ;
		}
		lstadd(&start[fd].lst, sub_dup(buffer, start[fd].b_read, 1));
	}
	if (line_size(start[fd].lst) == 0)
		cleanlst(&start[fd].lst, start[fd].last);
	start[fd].val = get_line(start[fd].lst);
	cleanlst(&start[fd].lst, start[fd].last);
	return (start[fd].val);
}
