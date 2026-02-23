/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratojo <maratojo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:44:20 by maratojo          #+#    #+#             */
/*   Updated: 2026/02/23 10:53:03 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handler.h"
#include "libft/libft.h"
#include "push_swap.h"
#include <limits.h>

static int	input_size(char **av)
{
	int	index;

	if (!av)
		return (0);
	index = 0;
	while (av[index])
		index++;
	return (index);
}

static int	input_(char *input)
{
	long	num;
	int		col;

	col = 0;
	if (input[col] == '-' || input[col] == '+')
		col++;
	if (!ft_isdigit(input[col]))
		return (1);
	while (ft_isdigit(input[col]))
		col++;
	if (input[col] != '\0')
		return (1);
	num = ft_atol(input);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

int	input_error(char **av, int free_arg)
{
	int	index;

	if (!av)
		return (1);
	index = 0;
	while (av[index])
	{
		if (input_(av[index]))
		{
			if (free_arg)
				free_all(av);
			return (1);
		}
		index++;
	}
	return (0);
}

int	duplicate_error(char **av, int free_arg)
{
	int	index;
	int	size;
	int	temp_index;

	if (!av)
		return (1);
	index = 0;
	size = input_size(av);
	while (index < size)
	{
		temp_index = index + 1;
		while (temp_index < size && ft_strcmp(av[index], av[temp_index]))
			temp_index++;
		if (temp_index < size && !ft_strcmp(av[index], av[temp_index]))
		{
			if (free_arg)
				free_all(av);
			return (1);
		}
		index++;
	}
	return (0);
}

void	int_error(t_stack **stack)
{
	t_stack	*current;
	t_stack	*runner;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->content == runner->content)
			{
				free_remaining(stack, NULL, NULL, 0);
				write(2, "Error\n", 7);
				exit(1);
			}
			runner = runner->next;
		}
		current = current->next;
	}
}
