/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finorako <finorako@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:21:50 by finorako          #+#    #+#             */
/*   Updated: 2026/02/20 17:35:23 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "error_handler.h"
#include "libft/libft.h"

int	get_input_size(char **av)
{
	int	index;

	index = 0;
	while (av[index])
		index++;
	return (index);
}

t_stack	*new_stack(int content)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->prev = NULL;
	stack->content = content;
	stack->next = NULL;
	return (stack);
}

t_stack	*laststack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stackadd_back(t_stack **stack, t_stack *new_stack)
{
	t_stack	*last;

	if (!stack)
		return ;
	if (*stack == NULL)
	{
		*stack = new_stack;
		return ;
	}
	last = laststack(*stack);
	last->next = new_stack;
	if (new_stack)
		new_stack->prev = last;
}

void	stack_init(t_stack **a, char **av, int free_arg)
{
	t_stack	*temp;
	int		index;

	if (input_error(av, free_arg) || duplicate_error(av, free_arg))
	{
		write(2, "Error\n", 7);
		exit(1);
	}
	index = 0;
	while (av[index])
	{
		temp = new_stack(ft_atoi(av[index]));
		if (free_remaining(a, temp, av, free_arg))
		{
			write(2, "Error\n", 7);
			exit(1);
		}
		stackadd_back(a, temp);
		index++;
	}
	if (free_arg)
		free_all(av);
}
