/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 08:44:36 by arakotot          #+#    #+#             */
/*   Updated: 2026/01/29 11:09:24 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_alloc_substr(size_t len)
{
	char	*substr;

	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	return (substr);
}

static void	ft_copy_substr(char const *s, unsigned int start, size_t len,
		char *substr)
{
	size_t	i;

	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	substr = ft_alloc_substr(len);
	if (!substr)
		return (NULL);
	if (len == 0)
		substr[0] = '\0';
	else
		ft_copy_substr(s, start, len, substr);
	return (substr);
}
