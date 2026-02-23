/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finorako <finorako@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:44:31 by finorako          #+#    #+#             */
/*   Updated: 2026/02/09 09:58:47 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_printf.h"

void	ft_putchar(char c, int *counter)
{
	*counter += write(1, &c, 1);
}

void	print_str(char *str, int *counter)
{
	int	index;

	if (str == NULL)
	{
		print_str(NULL_MESSAGE, counter);
		return ;
	}
	index = 0;
	while (str[index])
	{
		ft_putchar(str[index], counter);
		index++;
	}
}
