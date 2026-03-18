/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:52:07 by arakotot          #+#    #+#             */
/*   Updated: 2026/01/29 11:07:56 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*extract_word(char const *s, char c, int *index)
{
	char	*word;
	int		start;
	int		len;

	len = 0;
	while (s[*index] == c)
		(*index)++;
	start = *index;
	while (s[*index] && s[*index] != c)
	{
		len++;
		(*index)++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + start, len + 1);
	return (word);
}

static void	free_array(char **array, int i)
{
	while (i > 0)
		free(array[--i]);
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		words;
	int		i;
	int		index;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	i = 0;
	index = 0;
	while (i < words)
	{
		array[i] = extract_word(s, c, &index);
		if (!array[i])
		{
			free_array(array, i);
			return (NULL);
		}
		i++;
	}
	array[words] = NULL;
	return (array);
}
