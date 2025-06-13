/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:24:11 by jomaia            #+#    #+#             */
/*   Updated: 2025/04/21 11:23:22 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s1t;
	unsigned char	*s2t;

	s1t = (unsigned char *) s1;
	s2t = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1t[i] == s2t[i] && (s1t[i] != '\0')))
	{
		i++;
	}
	if (i == n)
		return (0);
	return (s1t[i] - s2t[i]);
}
