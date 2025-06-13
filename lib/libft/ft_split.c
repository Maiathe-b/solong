/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:54:12 by jomaia            #+#    #+#             */
/*   Updated: 2025/04/21 11:17:05 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	isword;
	size_t	words;

	words = 0;
	i = 0;
	isword = 0;
	while (s[i])
	{
		if (s[i] != c && isword == 0)
		{
			words++;
			isword++;
		}
		if (s[i] == c && isword == 1)
			isword--;
		i++;
	}
	return (words);
}

static void	free_all(char **res, int i)
{
	while (i >= 0)
		free(res[i--]);
	free(res);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	i;
	size_t	j;
	char	**res;

	j = 0;
	i = 0;
	words = ft_count_words(s, c);
	res = ft_calloc(words + 1, sizeof(char *));
	if (!res)
		return (NULL);
	while (words > 0)
	{
		while (s[j] == c && s[j + 1])
			j++;
		res[i] = ft_substr(&s[j], 0, ft_wordlen(&s[j], c));
		if (!res[i])
			free_all(res, i);
		i++;
		j = j + ft_wordlen(&s[j], c);
		words--;
	}
	res[i] = 0;
	return (res);
}
