/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finorako <finorako@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:52:22 by finorako          #+#    #+#             */
/*   Updated: 2026/02/20 16:56:36 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "swap_command.h"

void	medium_sort(t_stack **a, t_stack **b, t_bench *detail)
{
	int	chunk;
	int	index;

	if (!a || !b || stack_is_sorted(*a))
		return ;
	chunk = detail->size / 30;
	if (detail->size == 100)
		chunk = detail->size / 16;
	index = 0;
	while (*a)
	{
		while (index < detail->size)
		{
			if ((*a)->index <= chunk + index)
			{
				push(a, b, 'b', detail);
				index++;
			}
			else
				ra(a, 'a', detail);
		}
	}
	push_remaining(b, a, detail);
}
