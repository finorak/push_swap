/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finorako <finorako@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:13:46 by finorako          #+#    #+#             */
/*   Updated: 2026/02/20 16:56:06 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				content;
	int				index;
}				t_stack;

typedef struct s_min_cost
{
	int	pos;
	int	lower_half_pos;
	int	upper_half_pos;
}				t_min_cost;

typedef struct s_bench
{
	float	disorder;
	char	*strategy;
	char	*time_complexity;
	int		size;
	int		hide;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}				t_bench;

t_stack			*new_stack(int content);

t_stack			*laststack(t_stack *stack);

int				stack_size(t_stack *stack);

float			calculate_disorder(t_stack *stack);

void			put_min_top(t_stack **a, t_bench *detail);

int				stack_is_sorted(t_stack *stack);

void			stack_init(t_stack **stack, char **av, int free_arg);

void			push_swap(t_stack **a, t_stack **b, t_bench *detail);

int				get_input_size(char **av);

void			free_all(char **av);

void			stackadd_back(t_stack **stack, t_stack *new_stack);

void			handle_three(t_stack **stack, t_bench *detail);

void			handle_min(t_stack **a, t_stack **b, int size, t_bench *detail);

void			bench(t_bench *detail);

void			push(t_stack **a, t_stack **b, char c, t_bench *detail);

void			swap(t_stack **stack);

void			rotate(t_stack **stack);

void			reverse_rotate(t_stack **stack);

void			complex_sort(t_stack **a, t_stack **b, t_bench *detail);

void			medium_sort(t_stack **a, t_stack **b, t_bench *detail);

void			simple_sort(t_stack **a, t_stack **b, t_bench *detail);

void			get_sorted_arr(t_stack *stack);

int				ft_strcmp(char *s1, char *s2);

char			*ft_get_algo(char *str);

void			push_remaining(t_stack **b, t_stack **a, t_bench *detail);

void			put_in_range(t_stack **a, t_bench *detatil, int range);
#endif
