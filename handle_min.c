/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finorako <finorako@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:18:18 by finorako          #+#    #+#             */
/*   Updated: 2026/02/18 12:06:28 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "swap_command.h"

static int	find_min_index(t_stack *stack)
{
	int	min_index;
	int	pos;
	int	min_pos;

	if (!stack)
		return (-1);
	min_index = stack->index;
	pos = 0;
	min_pos = 0;
	while (stack)
	{
		if (min_index > stack->index)
		{
			min_index = stack->index;
			min_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}

void	put_min_top(t_stack **a, t_bench *detail)
{
	int	min_index;
	int	size;
	int	reverse;

	min_index = find_min_index(*a);
	if (min_index < 0)
		return ;
	size = stack_size(*a);
	if (min_index < size / 2)
	{
		while (min_index--)
			ra(a, 'a', detail);
		return ;
	}
	reverse = size - min_index;
	while (reverse--)
		rra(a, 'a', detail);
}

void	handle_min(t_stack **a, t_stack **b, int size, t_bench *detail)
{
	int	index;

	index = (detail->size - 1) / 2;
	while (index--)
	{
		put_min_top(a, detail);
		if (stack_is_sorted(*a))
			break ;
		push(a, b, 'b', detail);
	}
	index = (size - 1) / 2;
	handle_three(a, detail);
	if (*b && (*b)->next)
	{
		if ((*b)->content < (*b)->next->content)
			sa(b, 'b', detail);
	}
	while (index--)
		push(b, a, 'a', detail);
}
