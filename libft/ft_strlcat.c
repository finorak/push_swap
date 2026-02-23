/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratojo <maratojo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:21:27 by maratojo          #+#    #+#             */
/*   Updated: 2026/02/23 16:31:51 by maratojo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t	size)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	src_len;

	len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= len)
		return (size + src_len);
	i = 0;
	j = len;
	while (src[i] != '\0' && i < size - len - 1)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (len + src_len);
}
