/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 09:33:32 by arakotot          #+#    #+#             */
/*   Updated: 2026/01/29 13:48:37 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*source;

	dst = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (dst < source)
	{
		i = 0;
		while (i < n)
		{
			dst[i] = source[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			dst[i - 1] = source[i - 1];
			i--;
		}
	}
	return (dest);
}
