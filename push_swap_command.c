/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finorako <finorako@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:04:02 by finorako          #+#    #+#             */
/*   Updated: 2026/02/18 11:12:21 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	sa(t_stack **stack, char c, t_bench *detail)
{
	swap(stack);
	if (c == 'a')
		detail->sa += 1;
	else if (c == 'b')
		detail->sb += 1;
	if (!detail->hide)
		ft_printf("s%c\n", c);
}

void	ss(t_stack **a, t_stack **b, t_bench *detail)
{
	swap(a);
	swap(b);
	detail->ss += 1;
	if (!detail->hide)
		ft_printf("ss\n");
}

void	ra(t_stack **stack, char c, t_bench *detail)
{
	rotate(stack);
	if (c == 'a')
		detail->ra += 1;
	else if (c == 'b')
		detail->rb += 1;
	if (!detail->hide)
		ft_printf("r%c\n", c);
}

void	rra(t_stack **stack, char c, t_bench *detail)
{
	reverse_rotate(stack);
	if (c == 'a')
		detail->rra += 1;
	else if (c == 'b')
		detail->rrb += 1;
	if (!detail->hide)
		ft_printf("rr%c\n", c);
}

void	rrr(t_stack **a, t_stack **b, t_bench *detail)
{
	reverse_rotate(a);
	reverse_rotate(b);
	detail->rrr += 1;
	if (!detail->hide)
		ft_printf("rrr\n");
}
