/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finorako <finorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 08:32:01 by finorako          #+#    #+#             */
/*   Updated: 2026/02/18 14:23:05 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static float	count_total_pairs(int size)
{
	return ((float)size * (size - 1) / 2.0);
}

float	calculate_disorder(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;
	float	total_pairs;
	int		errors;
	int		size;

	size = stack_size(stack);
	errors = 0;
	current = stack;
	while (current && current->next)
	{
		runner = current->next;
		while (runner)
		{
			if (current->content > runner->content)
				errors++;
			runner = runner->next;
		}
		current = current->next;
	}
	total_pairs = count_total_pairs(size);
	return ((float)errors / total_pairs);
}
