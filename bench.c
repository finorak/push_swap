/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finorako <finorako@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:36:44 by finorako          #+#    #+#             */
/*   Updated: 2026/02/18 14:20:16 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static void	print_disorder(float disorder)
{
	int	first;
	int	last;

	first = (int)disorder;
	last = (int)((disorder - first) * 100);
	if (first < 10)
		ft_printf("0%d.", first);
	else
		ft_printf("%d.", first);
	if (last < 10)
		ft_printf("0%d%%\n", last);
	else
		ft_printf("%d%%\n", last);
}

static int	total_ops(t_bench	*detail)
{
	int	total;

	total = detail->ra + detail->rb + detail->rr;
	total += detail->rra + detail->rrb + detail->rrr;
	total += detail->sa + detail->sb + detail->ss;
	total += detail->pa + detail->pb;
	return (total);
}

void	bench(t_bench *detail)
{
	if (!detail || !detail->hide)
		return ;
	ft_printf("[bench] disorder:   ");
	print_disorder(detail->disorder);
	ft_printf("[bench] strategy:   %s / %s\n", detail->strategy,
		detail->time_complexity);
	ft_printf("[bench] total_ops:  %d\n", total_ops(detail));
	ft_printf("[bench] sa:  %d  sb:  %d  ss:  %d  pa:  %d  pb:  %d\n",
		detail->sa, detail->sb, detail->ss, detail->pa, detail->pb);
	ft_printf("[bench] ra:  %d  rb:  %d  rr:  %d  rra:  %d rrb:  %d  rrr: %d\n",
		detail->ra, detail->rb, detail->rr, detail->rra,
		detail->rrb, detail->rrr);
}
