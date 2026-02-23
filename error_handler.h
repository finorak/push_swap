/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finorako <finorako@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:34:40 by finorako          #+#    #+#             */
/*   Updated: 2026/02/23 10:52:48 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# include "push_swap.h"

long	ft_atol(const char *str);

int		input_error(char **av, int free_arg);

int		duplicate_error(char **av, int free_arg);

int		free_remaining(t_stack **stack, t_stack *temp, char **av, int free_arg);

void	int_error(t_stack **stack);
#endif
