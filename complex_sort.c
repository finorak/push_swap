/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finorako <finorako@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 07:50:10 by finorako          #+#    #+#             */
/*   Updated: 2026/02/23 14:43:12 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "swap_command.h"

static int	find_max_index(t_stack *stack)
{
	int	max_index;
	int	max_pos;
	int	pos;

	if (!stack)
		return (-1);
	pos = 0;
	max_pos = 0;
	max_index = stack->index;
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			max_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (max_pos);
}

static void	put_max_top(t_stack **stack, t_bench *detail, char c)
{
	int	max_pos;
	int	reverse;
	int	size;

	if (!stack || !*stack)
		return ;
	max_pos = find_max_index(*stack);
	if (max_pos < 0)
		return ;
	size = stack_size(*stack);
	if (max_pos <= size / 2)
	{
		while (max_pos--)
			ra(stack, c, detail);
		return ;
	}
	reverse = size - max_pos;
	while (reverse--)
		rra(stack, c, detail);
}

void	push_remaining(t_stack **b, t_stack **a, t_bench *detail)
{
	if (!a || !b || !detail)
		return ;
	while (*b)
	{
		put_max_top(b, detail, 'b');
		push(b, a, 'a', detail);
	}
}

void	complex_sort(t_stack **a, t_stack **b, t_bench *detail)
{
	int	chunk;
	int	index;

	chunk = detail->size / 16;
	if (chunk == 500)
		chunk = 30;
	index = 0;
	while (*a)
	{
		if ((*a)->index <= index)
		{
			push(a, b, 'b', detail);
			ra(b, 'b', detail);
			index++;
		}
		else if ((*a)->index <= index + chunk)
		{
			push(a, b, 'b', detail);
			index++;
		}
		else
			ra(a, 'a', detail);
	}
	push_remaining(b, a, detail);
}
