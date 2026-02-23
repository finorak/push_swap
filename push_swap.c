/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratojo <maratojo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:16:39 by finorako          #+#    #+#             */
/*   Updated: 2026/02/23 14:46:27 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "swap_command.h"

static int	base_algo(t_stack **a, t_stack **b, t_bench *detail)
{
	if (detail->size == 2)
	{
		sa(a, 'a', detail);
		return (1);
	}
	else if (detail->size == 3)
	{
		handle_three(a, detail);
		return (1);
	}
	else if (detail->size == 4)
	{
		handle_min(a, b, 3, detail);
		return (1);
	}
	else if (detail->size == 5)
	{
		handle_min(a, b, 5, detail);
		return (1);
	}
	return (0);
}

static void	adaptive(t_stack **a, t_stack **b, t_bench *detail)
{
	detail->strategy = "Adaptive";
	if (detail->disorder < 20)
	{
		detail->time_complexity = "O(n2)";
		if (!base_algo(a, b, detail))
			selection_sort(a, b, detail);
	}
	else if (20 <= detail->disorder && detail->disorder <= 50)
	{
		detail->time_complexity = "O(n√n)";
		if (!base_algo(a, b, detail))
			medium_sort(a, b, detail);
	}
	else
	{
		detail->time_complexity = "O(nlogn)";
		if (!base_algo(a, b, detail))
			complex_sort(a, b, detail);
	}
}

static void	choose_algo(t_stack **a, t_stack **b, t_bench *detail)
{
	if (!ft_strcmp(detail->strategy, "simple"))
	{
		detail->time_complexity = "O(n2)";
		detail->strategy = "Simple";
		base_algo(a, b, detail);
		selection_sort(a, b, detail);
	}
	else if (!ft_strcmp(detail->strategy, "medium"))
	{
		detail->time_complexity = "O(n√n)";
		detail->strategy = "Medium";
		if (!base_algo(a, b, detail))
			medium_sort(a, b, detail);
	}
	else if (!ft_strcmp(detail->strategy, "complex"))
	{
		detail->time_complexity = "O(nlogn)";
		detail->strategy = "Complex";
		if (!base_algo(a, b, detail))
			complex_sort(a, b, detail);
	}
	else
		adaptive(a, b, detail);
}

void	push_swap(t_stack **a, t_stack **b, t_bench *detail)
{
	if (stack_is_sorted(*a))
		return ;
	detail->disorder = calculate_disorder(*a) * 100;
	choose_algo(a, b, detail);
}
