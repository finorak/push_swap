/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finorako <finorako@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:20:45 by finorako          #+#    #+#             */
/*   Updated: 2026/02/11 23:26:04 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "swap_command.h"

static void	double_instructions(t_stack **a, char c, t_bench *detail)
{
	int	first;
	int	seconde;
	int	third;

	first = (*a)->content;
	seconde = (*a)->next->content;
	third = (*a)->next->next->content;
	if (first < seconde && first < third && seconde > third)
	{
		rra(a, c, detail);
		sa(a, c, detail);
	}
	else if (first < seconde && seconde > third && first < third)
	{
		ra(a, c, detail);
		sa(a, c, detail);
	}
	else if (first > seconde && seconde > third && first > third)
	{
		sa(a, c, detail);
		rra(a, c, detail);
	}
}

void	handle_three(t_stack **a, t_bench *detail)
{
	int	first;
	int	seconde;
	int	third;

	first = (*a)->content;
	seconde = (*a)->next->content;
	third = (*a)->next->next->content;
	if (first < seconde && seconde > third && first > third)
		rra(a, 'a', detail);
	else if (first > seconde && seconde < third && first < third)
		sa(a, 'a', detail);
	else if (first > seconde && seconde < third && first > third)
		ra(a, 'a', detail);
	else
		double_instructions(a, 'a', detail);
}
