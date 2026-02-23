/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finorako <finorako@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 07:59:35 by finorako          #+#    #+#             */
/*   Updated: 2026/02/18 14:58:34 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "error_handler.h"
#include "libft/libft.h"

static void	init_counter_value(t_bench *detail)
{
	detail->hide = 0;
	detail->strategy = "Adaptive";
	detail->time_complexity = NULL;
	detail->ra = 0;
	detail->rb = 0;
	detail->rr = 0;
	detail->sa = 0;
	detail->ss = 0;
	detail->sb = 0;
	detail->rra = 0;
	detail->rrb = 0;
	detail->rrr = 0;
	detail->pa = 0;
	detail->pb = 0;
}

static void	init(int ac, char **av, t_stack **stack, t_bench *detail)
{
	char	*strategy;

	if (ac <= 0)
		exit(1);
	if (ac >= 2 && !ft_strcmp(av[0], "--bench"))
	{
		detail->hide = 1;
		ac--;
		++av;
	}
	if (ac >= 2)
	{
		strategy = ft_get_algo(av[0]);
		if (strategy)
		{
			detail->strategy = strategy;
			ac--;
			++av;
		}
	}
	if (ac == 1)
		av = ft_split(av[0], ' ');
	stack_init(stack, av, ac == 1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	detail;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	init_counter_value(&detail);
	init(ac - 1, ++av, &a, &detail);
	detail.size = stack_size(a);
	get_sorted_arr(a);
	int_error(&a);
	push_swap(&a, &b, &detail);
	bench(&detail);
	free_remaining(&a, NULL, av, 0);
	return (0);
}
