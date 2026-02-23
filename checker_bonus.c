/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratojo <maratojo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:04:16 by maratojo          #+#    #+#             */
/*   Updated: 2026/02/19 09:25:47 by maratojo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker_bonus.h"
#include "get_next_line_bonus.h"
#include "libft/libft.h"

static int	execute_swap_push_command(t_stack **a, t_stack **b, char *cmd)
{
	if (ft_strcmp(cmd, "sa") == 0)
		swap(a);
	else if (ft_strcmp(cmd, "sb") == 0)
		swap(b);
	else if (ft_strcmp(cmd, "ss") == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strcmp(cmd, "pa") == 0)
		push1(b, a);
	else if (ft_strcmp(cmd, "pb") == 0)
		push1(a, b);
	else
		return (0);
	return (1);
}

static int	execute_rotate_command(t_stack **a, t_stack **b, char *cmd)
{
	if (ft_strcmp(cmd, "ra") == 0)
		rotate(a);
	else if (ft_strcmp(cmd, "rb") == 0)
		rotate(b);
	else if (ft_strcmp(cmd, "rr") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strcmp(cmd, "rra") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(cmd, "rrb") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(cmd, "rrr") == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		return (0);
	return (1);
}

static int	execute_command(t_stack **a, t_stack **b, char *cmd)
{
	if (execute_swap_push_command(a, b, cmd))
		return (1);
	if (execute_rotate_command(a, b, cmd))
		return (1);
	return (0);
}

static int	read_commands(t_stack **a, t_stack **b)
{
	char	*line;
	int		result;

	line = get_next_line(0);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		result = execute_command(a, b, line);
		free(line);
		if (!result)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		line = get_next_line(0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		result;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (ac == 2)
		stack_init(&a, ft_split(av[1], ' '), 1);
	else
		stack_init(&a, av + 1, 0);
	int_error(&a);
	result = read_commands(&a, &b);
	if (result)
	{
		if (stack_is_sorted(a) && !b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free_remaining(&a, NULL, NULL, 0);
	free_remaining(&b, NULL, NULL, 0);
	return (0);
}
