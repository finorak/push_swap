/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finorako <finorako@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:03:52 by finorako          #+#    #+#             */
/*   Updated: 2026/02/11 16:42:17 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handler.h"
#include "push_swap.h"
#include <stdlib.h>

void	free_all(char **av)
{
	int	index;

	index = 0;
	while (av[index])
	{
		free(av[index]);
		index++;
	}
	free(av);
}

int	free_remaining(t_stack **stack, t_stack *temp, char **av, int free_arg)
{
	t_stack	*next;

	if (temp)
		return (0);
	if (free_arg)
		free_all(av);
	if (!stack || !*stack)
		return (1);
	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	*stack = NULL;
	return (1);
}
