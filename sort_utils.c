/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratojo <maratojo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:43:05 by maratojo          #+#    #+#             */
/*   Updated: 2026/02/23 10:48:15 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	fill_array(t_stack *stack, int *tab)
{
	int	i;

	i = 0;
	while (stack)
	{
		tab[i] = stack->content;
		stack = stack->next;
		i++;
	}
}

static void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	k;
	int	tmp;

	i = 0;
	while (i < size)
	{
		k = i + 1 ;
		while (k < size)
		{
			if (tab[i] > tab[k])
			{
				tmp = tab[k];
				tab[k] = tab[i];
				tab[i] = tmp;
			}
			k++;
		}
		i++;
	}
}

static int	find_index(int *tab, int size, int content)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == content)
			return (i);
		i++;
	}
	return (0);
}

static void	assign_indexe(t_stack *stack, int *tab, int size)
{
	while (stack)
	{
		stack->index = find_index(tab, size, stack->content);
		stack = stack->next;
	}
}

void	get_sorted_arr(t_stack *stack)
{
	int	size;
	int	*tab;

	size = stack_size(stack);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return ;
	fill_array(stack, tab);
	ft_sort_int_tab(tab, size);
	assign_indexe(stack, tab, size);
	free (tab);
}
