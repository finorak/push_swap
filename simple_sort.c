/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finorako <finorako@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 09:15:04 by finorako          #+#    #+#             */
/*   Updated: 2026/02/14 10:10:59 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack **a, t_stack **b, t_bench *detail)
{
	if (!a || !b || stack_is_sorted(*a))
		return ;
	while (*a && (*a)->next)
	{
		put_min_top(a, detail);
		if (stack_is_sorted(*a))
			break ;
		push(a, b, 'b', detail);
	}
	while (*b)
		push(b, a, 'a', detail);
}
