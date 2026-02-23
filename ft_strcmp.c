/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finorako <finorako@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:08:42 by finorako          #+#    #+#             */
/*   Updated: 2026/02/18 11:08:03 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] || s2[index])
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	return (0);
}

char	*ft_get_algo(char *str)
{
	char	*algos[5];
	int		index;

	index = 0;
	algos[0] = "--simple";
	algos[1] = "--medium";
	algos[2] = "--complex";
	algos[3] = "--adaptive";
	algos[4] = NULL;
	while (algos[index])
	{
		if (!ft_strcmp(str, algos[index]))
			return (algos[index] + 2);
		index++;
	}
	return (NULL);
}
